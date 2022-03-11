import sys

def scan_cake(n):
    mnx = sys.maxsize
    mxx = -sys.maxsize
    for i in range(n):
        x, y = input().split()
        x = int(x)
        mnx = min(mnx, x)
        mxx = max(mxx, x)
    return (mnx, mxx)


n, m = input().split()
n = int(n)
m = int(m)

cake1 = scan_cake(n)
cake2 = scan_cake(m)

if max(cake1[0], cake2[0]) > min(cake1[1], cake2[1]):
    print("No Collision!")
else:
    print("Collision!")