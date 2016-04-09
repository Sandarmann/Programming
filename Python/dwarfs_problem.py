import sys
import math

class Node:
    def __init__(self, value):
        self.v = value
        self.dist=0
        self.adj=set()
    def getAdj(self):
        return self.adj
        
def BFS(start):
    max = 0
    giants[start].dist = 0
    q = set()
    q.add(start)
    while(q): #The solutions wasn't to get the depth of the tree but to find the longest path within the tree, this meant retreading old nodes.
        n = q.pop()
        for a in giants[n].getAdj():
            if giants[a].dist < giants[n].dist + 1: #If the giants old dist is less then the newfound dist than we swap the dist and then compare to max
                giants[a].dist=giants[n].dist + 1
            if giants[a].dist > max:
                max = giants[a].dist
            q.add(a)
    return max
giants={}
roots = set()
keys=set()
n = int(raw_input()) # the number of relationships of influence
for i in xrange(n):
     # x: a relationship of influence between two people (x influences y)
    x, y = [int(j) for j in raw_input().split()]
    if x not in giants:
        n = Node(x)
        n.adj.add(y)
        giants[x]=n
    else:
        n = giants[x]
        n.adj.add(y)
        giants[x] = n
    if y not in giants:
        giants[y] = Node(y)
    if y not in keys:
        keys.add(y)
    if x not in roots and x not in keys:
        roots.add(x)
        
starts_possible = set(roots)-set(keys)
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