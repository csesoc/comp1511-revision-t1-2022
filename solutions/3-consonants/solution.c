#include <stdio.h>
int isVowel[200], n, numVowels, numConsonants;
int main() {
	isVowel['A'] = isVowel['E'] = isVowel['I'] = isVowel['O'] = isVowel['U'] = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char c;
		scanf(" %c", &c);
		numVowels += isVowel[c];
		numConsonants += !isVowel[c];
	}
	if (numVowels > numConsonants) printf("VOWELS\n");
	else if (numVowels < numConsonants) printf("CONSONANTS\n");
	else printf("EQUAL\n");
}