import sys
import math

def find_path(graph, start, end, path=[]):
        path = path + [start]
        if start == end:
            return path
        if not graph.has_key(start):
            return None
        for node in graph[start]:
            if node not in path:
                newpath = find_path(graph, node, end, path)
                if newpath: return newpath
        return None
        

n = int(raw_input()) # the number of adjacency relations
edges = {}

for i in xrange(n):
     # xi: the ID of a person which is adjacent to yi
     # yi: the ID of a person which is adjacent to xi
    xi, yi = [int(j) for j in raw_input().split()]
    if xi not in edges:
        edges[xi] = []
    edges[xi].append(yi)
    if yi not in edges:
        edges[yi] = []
    edges[yi].append(xi)
print >> sys.stderr, edges
    
a = []
b = []
for i in edges:
    for j in edges:
        b.append(find_path(edges, i, j ))
    a.append(max(map(len,b)))
    b = []
#print >> sys.stderr, min(map(len,a)) #maps the length of all of the subarrays and reports the minimum
#print >> sys.stderr, a
print min(a)-1


#The point of this excersise is to find the shortest path to fill out the tree so that you find the optimal vertex to start with. 
#With that said I grabbed the max list for fleshing out the tree from the vertex then added that to another set. Once that is done 
#I grab the min of all the maxs then subtract 1 (itself) from the length.