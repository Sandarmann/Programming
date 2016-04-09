import sys
import math
special_cards = {'2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9, '10':10, 'J':11, 'Q':12, 'K':13, 'A':14}
# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = int(raw_input()) # the number of cards for player 1
c1 = []
c2 = []
for i in xrange(n):
    cardp_1 = raw_input() # the n cards of player 1
    c1 += [special_cards[cardp_1[:-1]]]
m = int(raw_input()) # the number of cards for player 2
for i in xrange(m):
    cardp_2 = raw_input() # the m cards of player 2
    c2 += [special_cards[cardp_2[:-1]]]

down1 = []
down2 = []
rounds = 0
while c1 and c2:
    cur1 = c1.pop(0)
    cur2 = c2.pop(0)
    print >> sys.stderr, "cur1", cur1, "cur2", cur2
    print >> sys.stderr, "c1",c1,"c2",c2
    print >> sys.stderr, rounds
#    print >> sys.stderr, "down1", down1, "down2", down2
    if cur1 == cur2:
        down1.append(cur1)
        down2.append(cur2)
        if len(c1) > 3: 
            for i in range(3):
                print >> sys.stderr, c1
                down1.append(c1.pop(0))
        else:
            c2 = []
            c1 = []
        if len(c2) > 3:
            for i in range(3):
                down2.append(c2.pop(0))
        else:
            c2 = []
            c1 = []
    elif cur1 > cur2:
        down1.append(cur1)
        down2.append(cur2)
        c1.extend(down1)
        c1.extend(down2)
        down1 = []
        down2 = []
        rounds = rounds + 1
    elif cur1 < cur2:
        down1.append(cur1)
        down2.append(cur2)
        c2.extend(down1)
        c2.extend(down2)
        down2 = []
        down1 = []
        rounds = rounds + 1
   
        
print >> sys.stderr, c1, c2, rounds
if c1:
    print "1", rounds
elif c2:
    print "2", rounds
else:
    print "PAT"
# Write an action using print
# To debug: print >> sys.stderr, "Debug messages..."

