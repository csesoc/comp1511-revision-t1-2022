import random

vowels = "aeiou"
cons = "bcdfghjklmnpqrstvwxyz"

vowel = random.randrange(2)
n = random.randint(2, 1024)

word = []
lb = []

for i in range(n):
    filled = random.randrange(10)
    if filled > 4:
        if vowel == i % 2:
            word.append(random.choice(vowels))
        else:
            word.append(random.choice(cons))
    else:
        word.append('-')
    #if vowel == i % 2:
        #lb.append(random.choice(vowels))
    #else:
    lb.append(random.choice(vowels + cons))
print(n)
print(''.join(word))
print(''.join(sorted(lb, reverse=True)))



