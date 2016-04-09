from collections import defaultdict
from heapq import *

def dijkstra(edges, start, to):
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

    return [float("inf")]

if __name__ == "__main__":
    edges = [
        ("A", "B"),
        ("A", "D"),
        ("B", "C"),
        ("B", "D"),
        ("B", "E"),
        ("C", "E"),
        ("D", "F"),
        ("D", "E"),
        ("E", "F"),
        ("E", "G"),
        ("F", "G")
    ]

    print "=== Dijkstra ==="
    print edges
    print "A -> E:"
    print dijkstra(edges, "A", "E")
    print "F -> G:"
    print dijkstra(edges, "F", "G")
