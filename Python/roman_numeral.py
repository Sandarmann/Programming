import sys
import math

r=["I","IV","V","IX","X","XL","L","LX" ,"C","CD", "D", "DC","M"]
n=[1,4,5,9,10,40,50,90,100,400,500,900,1000]
#x=int(raw_input())
x=3
a=""
num = []
n.reverse()
r.reverse()
for i in str(x):
    num +=i
num.reverse()
for i in num:
    k = i + ('0' * num.index(i))
    for q in n:
        if q < k:
        	print("NO"
            a+=r[n.index(q)]
    #if int(k) in n:
     #   a+=str(r[n.index(int(k))])
    print >> sys.stderr, a#i
print a
