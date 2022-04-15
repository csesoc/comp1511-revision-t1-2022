import random
import sys

CHARS = "&*"
LENGTH = int(sys.argv[1])

print(LENGTH)

final_string = ""

for _ in range(LENGTH):
    final_string += CHARS[random.randint(0, 1)]

print(final_string)
