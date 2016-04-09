# Enter your code here. Read input from STDIN. Print output to STDOUT
from collections import defaultdict
from heapq import heappush, heappop
map = {}
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def __eq__(self, other): #for python 2, otherwise use __cmp__ python3
        return other and self.x == other.x and self.y == other.y
    def __hash__(self):
        return hash((self.x, self.y))
def h(start, goal): #using Point class
    return (abs(goal.y - start.y ) + abs(goal.x - start.x))

def getNeighbors(point):#might be able to assume you will never be at edge of map :D so no error checking for me bb
    left = point.x - 1
    right = point.x + 1
    up = point.y-1
    down = point.y + 1
    neighbors = []
    if(map[(left, point.y)] != '%' ):
        neighbors.append((left, point.y))
    if(map[(right, point.y)] != '%' ):
        neighbors.append((right, point.y))
    if(map[(point.x, up)] != '%' ):
        neighbors.append((point.x, up))
    if(map[(point.x, down)] != '%' ):
        neighbors.append((point.x, down))

    return neighbors

def reconstruct_path(cameFrom, current):
    totalPath =[]
    totalPath.append(current)
    while current in cameFrom:
        current = cameFrom[current]
        totalPath.append(current)
    return totalPath

def isInHeap(heap, point):
    for i in heap:
        if i[1] == point:
            return 1
    return 0

def AStar(start, goal):#points start and point goal
    closedSet = []
    openSet = []
    heappush(openSet, (0, start)) #create a heap which will prioritize the minimum value. We store a tuple (heuristic value, point) which we then pop off every time we need the best option
    cameFrom = {}
    gScore = {} #this might be totally unnecessary.. I will look into thisb
    gScore = defaultdict(lambda:999999, gScore)
    gScore[start] = 0; #indexed using point class
    while openSet:
        #get point with min fScore value from openSet
        current = heappop(openSet)
        #print current[1].x, current[1].y, current[0], "CURRENT"
        if current[1] == goal:
            return reconstruct_path(cameFrom, current[1])
        closedSet.append(current[1])
        for p in getNeighbors(current[1]): #returns a tuple
            neighbor = Point(p[0], p[1])
            if neighbor in closedSet:
                continue
            tentative_gScore = gScore[current[1]] + h(neighbor, goal) #adjusted the h function to add another 1 for these values... just because of the tentative thing
            if not isInHeap(openSet, neighbor) :
                heappush(openSet, (tentative_gScore,neighbor))
            elif tentative_gScore >= gScore[neighbor]:
                    continue
            cameFrom[neighbor] = current[1]
            gScore[neighbor] = tentative_gScore
    return {}
        
pacY, pacX= [int(i) for i in raw_input().split()]
goalY, goalX = [int(i) for i in raw_input().split()]
sizeY, sizeX = [int(i) for i in raw_input().split()]
#print pacX, pacY, goalX, goalY, sizeX, sizeY
for i in range(0,sizeY):
    a = raw_input()
    #print a
    for j, item in enumerate(list(a)): #enumerate to loop through with index
        map[(j, i)] = item
#for i in range(0, sizeY):
#    for j in range(0, sizeX):
#        print map[(j,i)],
#    print "\n",
#n = getNeighbors(Point(pacX, pacY)) #Works just fine, had to swap the x and the y above because it came in as rows then col...
#print n
blah = AStar(Point(pacX, pacY), Point(goalX, goalY))
print len(blah)-1 #subtract 1 for the initial start
for i in reversed(blah) : #They use row col rather than col row in a grid :p
    print i.y, i.x
#h = []
#heappush(h, (12 ,Point(2,3)))
#heappush(h, ( 32 , Point(1,3) ))

#heappush(h, (1 , Point(1,3)))
#for i in h:
 #   print i[1].x, i[1].y, i[0]