# Puts all responses after all guesses, rather than interleaving them

import os

for inputfile in os.scandir("tests/input"):
	with open(inputfile, "r") as f:
		N = int(f.readline())
		allowed_words = [f.readline().strip() for i in range(N)]
		K = int(f.readline())
		guesses = []
		responses = []
		for i in range(K):
			guesses.append(f.readline().strip())
			responses.append(f.readline().strip())

	with open(inputfile, "w") as f:
		f.write(str(N) + "\n")
		f.write("\n".join(allowed_words) + "\n")
		f.write(str(K) + "\n")
		f.write("\n".join(guesses) + "\n")
		f.write("\n".join(responses) + "\n")