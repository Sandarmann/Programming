import sys
import math
from collections import Counter


def nearestPoint(x):
    return min(enumerate(high_points), key = lambda i: abs(i[1][0] - x))
# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.
land = []
surface_n = int(raw_input()) # the number of points used to draw the surface of Mars.
for i in xrange(surface_n):
     # land_x: X coordinate of a surface point. (0 to 6999)
     # land_y: Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
    land_x, land_y = [int(j) for j in raw_input().split()]
    print >> sys.stderr, land_x , "land x" , land_y, "land_y"
    land.append((land_x, land_y))

flat_zone = []
f_zone_height = 0
for i,v in enumerate(land):
    if i != len(land)-1:
        if v[1] == land[i+1][1]:
            flat_zone.append(v[0])
            flat_zone.append(land[i+1][0])
            f_zone_height = v[1]
#print >> sys.stderr, flat_zone, f_zone_height

high_points = []
for i,v in enumerate(land):
    if v[1] > f_zone_height:
        high_points.append((v[0], v[1]))
#print >> sys.stderr, high_points
# game loop

while 1:
     # h_speed: the horizontal speed (in m/s), can be negative.
     # v_speed: the vertical speed (in m/s), can be negative.
     # fuel: the quantity of remaining fuel in liters.
     # rotate: the rotation angle in degrees (-90 to 90).
     # power: the thrust power (0 to 4).
    in_zone = False
    rotation = 0 #default
    thrust = 4 #default
    highest_point = ()
    x, y, h_speed, v_speed, fuel, rotate, power = [int(i) for i in raw_input().split()]
    a = [k[1] for k in land]
    
    if(high_points):
        print >> sys.stderr, nearestPoint(x)
        range_finish = x - min(flat_zone, key=lambda i: abs(x-i))
        if range_finish < 0:
            #print >> sys.stderr, "new list of high points in range", [k for k in high_points if k[0] >= x and k[0] <= x-range_finish]
            high_points = [k for k in high_points if k[0] >= x and k[0] <= x-range_finish]
        else:
            #print >> sys.stderr, "new list of high points in range", [k for k in high_points if k[0] >= x - range_finish and k[0] < x]
            high_points = [k for k in high_points if k[0] >= x and k[0] <= x-range_finish]
        print >> sys.stderr, high_points, "\n area to get too", flat_zone, "\n current x:", x
        if high_points:
            highest_point = max(high_points, key = lambda i: i[1]) #we should only worry about the highest point in the set
        print >> sys.stderr, "closest high point" ,highest_point
    #print >> sys.stderr, "new list of high points in range", [k for k in high_points if k[0]
    
    print >> sys.stderr , h_speed, flat_zone
    if x < min(flat_zone) and h_speed < 20 and not in_zone:
        if h_speed > 18:
            rotation -=10 * (h_speed/20)
        else:
            rotation += 10 * (h_speed/20)
    elif x > max(flat_zone) and h_speed < 20 and not in_zone:
        if h_speed < -18:
            print >> sys.stderr, "HEERE"
            rotation +=10 * (h_speed/20)
        else:
            rotation +=10 * (h_speed/20)
    else:
        print >> sys.stderr , "YO", rotation
        in_zone = True
        if h_speed > 15:
            rotation = 0 - rotate
        elif h_speed < -15:
            rotation = 0 + rotate
        elif h_speed != 0:
            rotation = rotate
    print >> sys.stderr, v_speed
    

    if in_zone:
        if v_speed  < -30 or h_speed < -10:
            thrust = 4
        else:
            thrust = thrust - 1
            
    print >> sys.stderr, f_zone_height, y
    if y - f_zone_height < 300:
        rotation = 0
    # Write an action usinrint
    # To debug: print >> sys.stderr, "Debug messages..."

    # rotate power. rotate is the desired rotation angle. power is the desired thrust power.
    print str(rotation), str(thrust)
