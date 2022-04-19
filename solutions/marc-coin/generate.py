import random

n = random.randrange(1000)
r = random.randrange(n)

print(n, r)

ids = [x for x in range(1000)]
usedIds = []
random.shuffle(ids)

bal = 100
transid = 0
transactions = []

for i in range(n):
    num = ids.pop()
    usedIds.append(num)
    sender = random.choice(["B", "E"])
    maxSend = 200 - bal if sender == "E" else bal
    send = random.randrange(maxSend)
    bal += send if sender == "E" else -send
    transactions.append((num, sender, send, bal))


for i in transactions:
    print(f'{i[0]:03}', i[2], i[1])

random.shuffle(usedIds)
for i in range(r):
    print(f'{usedIds[i]:03}')
