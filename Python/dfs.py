from collections import defaultdict
from heapq import *
INF = 9999999999

def floydwarshall(graph):
 
    # Initialize dist and pred:
    # copy graph into dist, but add infinite where there is
    # no edge, and 0 in the diagonal
    dist = {}
    pred = {}
    for u in graph:
        dist[u] = {}
        pred[u] = {}
        for v in graph:
            dist[u][v] = 1000
            pred[u][v] = -1
        dist[u][u] = 0
        for neighbor in graph[u]:
            dist[u][neighbor] = graph[u][neighbor]
            pred[u][neighbor] = u
 
    for t in graph:
        # given dist u to v, check if path u - t - v is shorter
        for u in graph:
            for v in graph:
                newdist = dist[u][t] + dist[t][v]
                if newdist < dist[u][v]:
                    dist[u][v] = newdist
                    pred[u][v] = pred[t][v] # route new path through t
 
    return dist, pred

def dijkstra(edges, start, to=None):
    g = defaultdict(list)
    for edge,adj_edge in edges:
        g[edge].append((1,adj_edge))

    q, seen = [(0,start,())], set()
    path=[]
    while q:
        (cost,v1,path) = heappop(q)
        if v1 not in seen:
            seen.add(v1)
            path = list(path) + [v1]
            if v1 == to: return (cost, path)

            for c, v2 in g.get(v1, ()):
                if v2 not in seen:
                    heappush(q, (cost+c, v2, path))

    return (cost, path)

edges = {0: {1:1}, 1: {0:1, 2:1}, 2: {1:1, 3:1, 4:1}, 3: {2:1}, 4: {2:1}}
#edges = {(0,1):1, (1,0):1, (2,1):1, (1,2):1, (2,3):1, (3,2):1, (2,4):1, (4,2):1}
graph = {0 : {1:6, 2:8},
         1 : {4:11},
         2 : {3: 9},
         3 : {},
         4 : {5:3},
         5 : {2: 7, 3:4}}
dist, pred =  floydwarshall(edges)
for v in pred:
    print v, pred[v]
for v in dist:
    a = dist[v]
    print v, a, dist[v][max(a, key= a.get)]
#edges = [(6, 8), (8, 6), (15, 1), (1, 15), (1, 14), (14, 1), (0, 3), (3, 0), (15, 13), (13, 15), (9, 15), (15, 9), (2, 5), (5, 2), (14, 10), (10, 14), (4, 9), (9, 4), (7, 2), (2, 7), (8, 7), (7, 8), (3, 4), (4, 3), (1, 6), (6, 1)]
#a = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 13, 14, 15]
# for i in a:

#     print dijkstra(edges, i)

