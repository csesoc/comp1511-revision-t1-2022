import random

n = random.randrange(1000)
print(n)

for i in range(n):
    k = random.randrange(10000)
    print(k)
    nums = [str(random.randrange(100)) for x in range(k)]
    print(" ".join(nums))


