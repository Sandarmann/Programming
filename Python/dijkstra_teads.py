import sys
import math
from collections import defaultdict
from heapq import *

def dijkstra(edges, start, limit ,to=None):
    #g = defaultdict(list)
    #for edge,adj_edge in edges:
    #    g[edge].append((1,adj_edge))
    g = edges
    q, seen = [(0,start,())], set()
    path=[]
    while q:
        (cost,v1,path) = heappop(q)
        if cost > limit:
            return
        if v1 not in seen:
            seen.add(v1)
            path = list(path) + [v1]
            if v1 == to: 
                return (cost, path)
            for c, v2 in g.get(v1, ()):
                if v2 not in seen:
                    heappush(q, (cost+c, v2, path))

    return (cost, path)

    
n = int(raw_input()) # the number of adjacency relations
edges = {}
num = []
for i in xrange(n):
     # xi: the ID of a person which is adjacent to yi
     # yi: the ID of a person which is adjacent to xi
    xi, yi = [int(j) for j in raw_input().split()]
    if xi not in edges:
        edges[xi] = []
    edges[xi].append((1, yi))
    if yi not in edges:
        edges[yi] = []
    edges[yi].append((1,xi))
num = [i for i in edges if len(edges[i]) > 1 and edges[i] not in num]
#print >> sys.stderr, edges, num

a= []
#num = list(set(num))
for i in num:
    v = dijkstra(edges,i, 900)
    #print >> sys.stderr, v
    if v:
        a.append(v[0])
#print >> sys.stderr, min(map(len,a)) #maps the length of all of the subarrays and reports the minimum
print >> sys.stderr, a 
print min(a)
