import sys
import math
#I think i have to do shortest path first. seems like I could

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.
houses = []
answers = []
n = int(raw_input())
xs = []
ys = []
for i in xrange(n):
    x, y = [int(j) for j in raw_input().split()]
    xs.append(x)
    ys.append(y)
    houses.append((x,y))
midy = (max(ys) - min(ys) )/2
most_common_y = max(ys, key=ys.count)
most_common_x = max(xs, key=xs.count)
print >> sys.stderr, houses, "midy", midy, "com y", most_common_y, "com x", most_common_x
##########################
cable_to_house_mid = 0
for i in ys:
    if midy != i:
        cable_to_house_mid += abs(i - midy)
cable_span_x = abs(max(xs) - min(xs))
print >> sys.stderr, cable_to_house_mid, cable_span_x
answers.append(cable_to_house_mid + cable_span_x)
##########################

cable_to_house_y = 0
for i in ys:
    if most_common_y != i:
        cable_to_house_y += abs(i - most_common_y)
cable_span_x = abs(max(xs) - min(xs))
print >> sys.stderr, cable_to_house_y, cable_span_x
answers.append(cable_to_house_y + cable_span_x)
##########################
cable_to_house_x = 0
cable_span_y = abs(max(ys)-min(ys))
for i in xs:
    if most_common_x != i:
        cable_to_house_x += abs(i - most_common_y)
print >> sys.stderr, cable_to_house_x, cable_span_y
answers.append(cable_to_house_x + cable_span_y)
##########################
# Write an action using print
# To debug: print >> sys.stderr, "Debug messages..."

print min(answers)
