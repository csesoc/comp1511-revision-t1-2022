# Solution by Jonathan
# T(n) is the nth triangular number,
# 1+2+3+...+n = n(n+1)/2
def T(n):
    return n * (n+1) // 2
    
A, B, C, D, E, F = map(int, input().split())

triangle_side = A + B + F - 2
# Alternatively, B+C+D-2 or D+E+F-2 also give the same result

ans = T(triangle_side) - T(B-1) - T(D-1) - T(F-1)

print(ans)
