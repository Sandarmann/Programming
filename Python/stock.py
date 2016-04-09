import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.
greatest_diff = 0
n = int(raw_input())
vs = raw_input()
vs = vs.split(" ")
vs = list(map(int, vs))
#print >> sys.stderr, len(vs)

diff = vs[0] - vs[1]
curr_sum = diff
max_sum = curr_sum

for i in range(1,n-1):
	diff = vs[i] - vs[i+1]
	if curr_sum > 0:
		curr_sum += diff
	else:
		curr_sum = diff
	if curr_sum > max_sum:
		max_sum = curr_sum


# Write an action using print
# To debug: print >> sys.stderr, "Debug messages..."

print -max_sum if -max_sum < 0 else 0
