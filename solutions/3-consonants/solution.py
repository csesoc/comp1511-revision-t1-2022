N = int(input())
vowels = 0
for char in input().strip():
	if char in 'AEIOU':
		vowels += 1
consonants = N - vowels
if vowels > consonants:
	print('VOWELS')
elif vowels < consonants:
	print('CONSONANTS')
else:
	print('EQUAL')