import random

n_layers = random.randint(50_000, 100_000)
print(n_layers)

for _ in range(n_layers):
    print(random.randint(1, 10_000))
