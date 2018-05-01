'''input
2
1 5 10 3
1 2 2 2
'''

def gcd (a, b):
    if not a:
        return b
    return gcd (b % a, a)
 
for _ in range (int (input())):
    a, b, c, d = map (int, input().split())
    g = gcd (c, d)
    print (min ((a - b) % g, (b - a) % g)) 