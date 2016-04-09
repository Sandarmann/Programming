import sys
import math
#This thing does a breadth first search and measures the depth of the tree. We go from the top all the way down ot the last node
#We then grab the last node then do it again. This way allows us to measure the depth of the tree, We then take the length and
#add 1 (to ceil it) then we divide by 2 because this will be the max length of the tree...


class Node:
    def __init__(self, value):
        self.value = value
        self.edges = []
    def __eq__(self, other): #makes the comparison work correctly
        return self.value == other.value
    def addEdge(self, n):
        self.edges.append(n)
    def getEdges(self):
        return self.edges
    def getValue(self):
        return self.value
        
def BFS(graph, start):
    length = 0
    finish = Node(-1)
    a = max(graph) + 1
    depth = [-1] * a
    #print >> sys.stderr, depth
    depth[start] = 0
    print >> sys.stderr, depth[start]
    stack = []
    stack.append(start)
    #print >> sys.stderr, stack
    while(stack):
        father = stack.pop()
        print >> sys.stderr, "father value", father, "edges:", len(graph[father])
        for son in graph[father]:
            #print >> sys.stderr, "son.getValue in depth", depth[son], son, len(graph[son])
            if depth[son] == -1:
                print >> sys.stderr, "WHY"
                depth[son] = depth[father]+1
                if depth[son] > length:
                    length = depth[son]
                    finish = son
                print >> sys.stderr , "son: ", [i for i in graph[son]]
                stack.append(son)
                print >> sys.stderr, len(stack)
    return length, finish
        
graph = {}
n = int(raw_input()) # the number of adjacency relations
for i in xrange(n):
     # xi: the ID of a person which is adjacent to yi
     # yi: the ID of a person which is adjacent to xi
    xi, yi = [int(j) for j in raw_input().split()]
    if xi not in graph:
        graph[xi]=[]
    graph[xi].append(yi)
    if yi not in graph:
        graph[yi]=[]
    graph[yi].append(xi)

print >> sys.stderr, graph
#for i in graph:
#    print >> sys.stderr, i,
#    for a in graph[i].edges:
#        print >> sys.stderr, a.value,
#    print >> sys.stderr, '\n'
length, last = BFS(graph, 0)
length, last = BFS(graph, last)
print >> sys.stderr, length, last

# Write an action using print
# To debug: print >> sys.stderr, "Debug messages..."

# The minimal amount of steps required to completely propagate the advertisement
print (length+1)/2