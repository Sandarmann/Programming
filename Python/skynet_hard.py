import sys
import math
from collections import defaultdict
from heapq import *
#sSHIT DOES NOT FUCKING WORK. NEED TO START OVER
def djikstra(edges, f, t):
    g = defaultdict(list)
    for l,r in edges:
        g[l].append((1,r))

    q, seen = [(0,f,())], set()
    path=[]
    while q:
        (cost,v1,path) = heappop(q)
        if v1 not in seen:
            seen.add(v1)
            path = list(path) + [v1]
            if v1 == t: return (cost, path)

            for c, v2 in g.get(v1, ()):
                if v2 not in seen:
                    heappush(q, (cost+c, v2, path))

    return [float("inf")]


gateways = []
edges = []
n, l, e = [int(i) for i in raw_input().split()]
for i in xrange(l):
     # n1: N1 and N2 defines a link between these nodes
    n1, n2 = [int(j) for j in raw_input().split()]
    edges.append((n1,n2))
    edges.append((n2,n1))
    
for i in xrange(e):
    ei = int(raw_input()) # the index of a gateway node
    gateways.append(ei)
    
#print >> sys.stderr, edges_dict
# game loop
while 1:
    answers = {}
    edges_dict = {}
    si = int(raw_input()) # The index of the node on which the Skynet agent is positioned this turn
    multi_connections = []
    multi = {}
    tmp = []
    gateway_connections = {}
    for i in edges:
        n1 = i[0]
        n2 = i[1]
        if n1 not in edges_dict:
            edges_dict[n1] = []
        edges_dict[n1].append(n2)
        if n2 not in edges_dict:
            edges_dict[n2] = []
        edges_dict[n2].append(n1)
    for k in edges_dict:
        edges_dict[k] = list(set(edges_dict[k]))
    print >> sys.stderr, edges_dict
    for k in edges:
        if k[0] in gateways:
            if k[0] not in gateway_connections:
                gateway_connections[k[0]] = []
            gateway_connections[k[0]].append(k[1])
    print >> sys.stderr, gateway_connections, "gateway"
    
    
    multi_connections = [k for k in edges if k[1] in gateways]
    #print >> sys.stderr, multi_connections, "multi_co"
    for tup in multi_connections:
        if tup[0] not in multi:
            multi[tup[0]] = []
        multi[tup[0]].append(tup[1])
    #print >> sys.stderr, multi , "multi vor"

    tmp = [k for k in multi if len(multi[k]) == 1]   
    #print >> sys.stderr, tmp , "tmp"
    for i in tmp:   #removes all nodes with 1 connection
        multi.pop(i, None)
    #print >> sys.stderr, multi , "multi"
    
    
    for i in gateways:
#        print >> sys.stderr, djikstra(edges, si, i)
        if djikstra(edges, si, i) != [float("inf")]:
            cost,path = djikstra(edges, si, i)
            answers[(path[-2], path[-1])] =  cost
    #print >> sys.stderr, answers 
    min_value = min(answers.itervalues())
    print >> sys.stderr, min_value, "min value"
    print >> sys.stderr, multi, "multi "
    #use multi and filter into a tmp dict if no answer has a value of 1
    if min_value >1 and bool(multi):
        temp = {}
        for i in multi:
            if djikstra(edges, si, i) != [float("inf")]:
                cost,path = djikstra(edges, si, i)
                temp[(path[-2], path[-1])] =  cost
        print >> sys.stderr, temp, "temp"
        max_len = [k for k in gateway_connections.keys() if len(gateway_connections.get(k))==max([len(n) for n in gateway_connections.values()])]
        print >> sys.stderr, max_len, "max-Len"
        
        neighbors = []
        for i in temp:
            if i[0] in max_len:
                neighbors.append((i[0], i[1]))
        print >> sys.stderr, neighbors, "neighbors"
        
        if bool(neighbors):
            response = neighbors[0]
        # I now know that I need to find the one with the most neightbors connecting to gateways
        else: #if min_value > 1:
            check = {}
            for key in multi:
                #print >> sys.stderr, key
                if len(multi[key]) > 1 :
                    if key not in check:
                        check[key] = []
                check[key]=multi[key]
            temp = {}
            for i in check:
                if djikstra(edges, si, i) != [float("inf")]:
                    cost,path = djikstra(edges, si, i)
                    temp[(path[-2], path[-1])] =  cost  
            print >> sys.stderr, check, " check"
            print >> sys.stderr, min(check), "min check"
            print >> sys.stderr, temp, " tempcheck"
            for i in temp:
                if not any(a in edges_dict[i[0]] for a in gateways):
                    check.pop(i[1])
            t = {}
            for i in check:
                if djikstra(edges, si, i) != [float("inf")]:
                    cost,path = djikstra(edges, si, i)
                    t[(path[-2], path[-1])] =  cost  
            print >> sys.stderr, check, "checkasdfasd"
            print >> sys.stderr, t, " tcheck"
            if bool(t):
                print >> sys.stderr, min(t)[1], "min check"
            hall = edges_dict[si]
            blah = {}
            for i in hall:
                for j in edges_dict[i]:
                    if j in gateway_connections:
                        if i in gateway_connections[j]:
                            if i not in blah:
                                blah[i] = []
                            print >> sys.stderr, i, "i" ,gateway_connections[j]
                            blah[i].append(j)
            holyFuck = 0
            if bool(blah):
                break
                print >> sys.stderr, blah, "blah"
                print >> sys.stderr, max(blah, key= lambda x: len(set(blah[x])))
                max_key = max(blah, key= lambda x: len(set(blah[x])))
                if len(blah[max_key]) < 2:
                    holyFuck = 1 
            
            if holyFuck and bool(check): #get the immediate neighbors and if they have a node then no
                print >>sys.stderr , blah, " blah"
                print >> sys.stderr, check, " check"
                print >> sys.stderr, min(t)[1], check[min(t)[1]][0], "response"
                response = (min(t)[1], check[min(t)[1]][0])
            else:
                print >> sys.stderr, temp
                a = min(temp, key=temp.get)
                print >> sys.stderr, a
                b = multi[a[1]][0]
                print >> sys.stderr, b
                response = (a[1], b)
        if (response[0], response[1]) in edges:
            edges.remove((response[0], response[1]))
        if (response[1], response[0]) in edges:
            edges.remove((response[1], response[0]))
        print >> sys.stderr, response
        print str(response[0]) + " " + str(response[1])
    else:
        print >> sys.stderr, answers, "answers"
        min_keys = [k for k in answers if answers[k] == min_value]
        response = min_keys[0]
        print >> sys.stderr, min_keys, "min_keys"
        print >> sys.stderr, response, "response"
        edges.remove((response[0], response[1]))
        edges.remove((response[1], response[0]))
        print str(response[0]) + " " + str(response[1])
