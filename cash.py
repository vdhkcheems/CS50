from cs50 import get_float
while True:
    n = get_float("Change: ")
    if n>=0:
        break

n = n*100

a= int(n / 25)
b= n % 25
c= int(b / 10)
d= b % 10
e= int(d / 5)
f= d % 5
g= int(f / 1)

print(a+c+e+g)