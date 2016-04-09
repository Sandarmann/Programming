#!flask/bin/python

from flask import Flask, jsonify, abort, make_response, request, url_for
from flask.ext.httpauth import HTTPBasicAuth

app = Flask(__name__) #creates our Flask instance

tasks = [  #This creates GET info for us to transfer via JSON
	{
		'id' : 1,
		'title' : u'Buy groceries',
		'description' : u'Milk, Cheese, Pizza, Fruit, Tylenol',
		'done' : False
	},
	{
		'id' : 2,
		'title' : u'Learn Python',
		'description' : u'Need to find a good Python tutorial on the web',
		'done' : False
	}
]

#Authentication
auth = HTTPBasicAuth()

@auth.get_password
def get_password(username):
	if username == 'alek':
		return 'python'
	return None

@auth.error_handler
def unauthorizes():
	return make_response(jsonify({'error': 'unauthorized access'}), 403)

#Helper function that generates a public version of the task information so that no sensitive information is passed 
def make_public_task(task):
	new_task ={}
	for field in task:
		if field == 'id':
			new_task['uri'] = url_for('get_task', task_id=task['id'], _external=True)
		else:
			new_task[field] = task[field]
	return new_task

#POST
@app.route('/todo/api/v1.0/tasks', methods=['POST'])
def create_task():
	if not request.json or not 'title' in request.json:
		abort(400)
	task = {
		'id' : tasks[-1]['id'] + 1,
		'title' : request.json['title'],
		'description' : request.json.get('description', ""),
		'done': False
	}
	tasks.append(task)
	return jsonify({'task' : task}), 201 #201 is the HTTP code for "Created"

#PUT updates a resource

@app.route('/todo/api/v1.0/tasks/<int:task_id>', methods=['PUT'])
def update_task(task_id):
	task = [task for task in tasks if task['id'] == task_id]
	if len(task) == 0:
		abort(404)
	if not request.json:
		abort(400)
	if 'title' in request.json and type(request.json['title']) != unicode:
		abort(400)
	if 'description' in request.json and type(request.json['description']) is not unicode:
		abort(400)
	if 'done' in request.json and type(request.json['done']) is not bool:
		abort(400)
	task[0]['title'] = request.json.get('title', task[0]['title'])
	task[0]['description'] = request.json.get('description', task[0]['description'])
	task[0]['done'] = request.json.get('done', task[0]['done'])
	return jsonify({'task':make_public_task(task[0])})

#DELETE
@app.route('/todo/api/v1.0/tasks/<int:task_id>', methods=['DELETE'])
def delete_task(task_id):
	task = [task for task in tasks if task['id'] == task_id]
	if len(task) == 0:
		abort(404)
	tasks.remove(task[0])
	return jsonify({'result': True})

#GET
@app.route('/todo/api/v1.0/tasks', methods=['GET']) #An easier way of setting things to a specific URL
@auth.login_required
def get_tasks():
	return jsonify({'tasks':[make_public_task(task) for task in tasks]})

@app.route('/todo/api/v1.0/tasks/<int:task_id>', methods=['GET'])
@auth.login_required
def get_task(task_id):
	task = [task for task in tasks if task['id'] == task_id]
	if len(task) == 0:
		abort(404) #Makes the 404 page for any number task not found in the tasks JSON
	return jsonify({'task': make_public_task(task[0])})

@app.route('/')
def index():
    return "Hello, World"

#ERROR
@app.errorhandler(404)
def not_found(error):
	return make_response(jsonify({'error': 'Not found'}), 404)


if __name__ == '__main__':	#is defined so that this module may be run only when specifically designated
    app.run(debug=True)
