import sys
import math

class Node:
    def __init__(self, value):
        self.v = value
        self.dist=0
        self.adj=[]
    def getAdj(self):
        return self.adj
        
def BFS(start):
    max = 0
    found = [start]
    giants[start].dist = 0
    q = []
    q.append(start)
    while(q):
        n = q.pop(0)
        for a in giants[n].getAdj():
            if(a not in found):
                giants[a].dist=giants[n].dist + 1
                if giants[a].dist > max:
                    max = giants[a].dist
                found.append(a)
                q.append(a)
    return max
giants={}
roots = []
keys=[]
n = int(raw_input()) # the number of relationships of influence
for i in xrange(n):
     # x: a relationship of influence between two people (x influences y)
    x, y = [int(j) for j in raw_input().split()]
    if x not in giants:
        n = Node(x)
        n.adj.append(y)
        giants[x]=n
    else:
        n = giants[x]
        n.adj.append(y)
        giants[x] = n
    if y not in giants:
        giants[y] = Node(y)
    if y not in keys:
        keys.append(y)
    if x not in roots and x not in keys:
        roots.append(x)

starts_possible = list(set(roots)-set(keys))
print >> sys.stderr, starts_possible
answers = 0
orig_dict = dict(giants)
for j in starts_possible:
    giants = dict(orig_dict)
    a= BFS(j);
    if answers < a:
        answers = a
print >> sys.stderr, answers
print answers+1

