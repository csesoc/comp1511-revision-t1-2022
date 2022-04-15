import random

print("300 500")

first = [random.randint(0, 1000) for _ in range(300)]
second = [random.randint(0, 1000) for _ in range(500)]

print(" ".join(str(x) for x in first))
print(" ".join(str(y) for y in second))

second.sort(reverse=True)

print(sum(first) + sum(second[:300]))
