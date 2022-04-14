import sys

def scan_cake(n):
    mnx = sys.maxsize
    mxx = -sys.maxsize

    xs = [int(x) for x in input().split()]
    ys = [int(x) for x in input().split()]
    for x in xs:
        assert abs(x) <= 1_000_000_000
        mnx = min(mnx, x)
        mxx = max(mxx, x)
    for y in ys:
        assert abs(y) <= 1_000_000_000
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
