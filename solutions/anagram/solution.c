#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1024

int check_anagram(char first_word[MAX_SIZE],char second_word[MAX_SIZE]);
void remove_newline(char input[MAX_SIZE]);

int main (void) {
    char first_word[MAX_SIZE];
    char second_word[MAX_SIZE];
    printf("First word: ");
    fgets(first_word, MAX_SIZE, stdin);
    printf("Second word: ");
    fgets(second_word, MAX_SIZE, stdin);
    
    remove_newline(first_word);
    remove_newline(second_word);
    
    int check = check_anagram(first_word, second_word);
    
    if (check == 1) {
        printf("These two words are an anagram! \n");
    } else {
        printf("These two words are not an anagram! \n");
    }
    
    return 0;
    
}

//Removing newline from end of string function took from  ass 2 :P
void remove_newline(char input[MAX_SIZE]) {

    // Find the newline or end of string
    int index = 0;
    while (input[index] != '\n' && input[index] != '\0') {
        index++;
    }
    // Goto the last position in the array and replace with '\0'
    // Note: will have no effect if already at null terminator
    input[index] = '\0';
}


int check_anagram(char first_word[MAX_SIZE], char second_word[MAX_SIZE]) {

  //Arrays that stores frequency of characters that appears in both words
  //where alpha_first[0] will give frequency of letter 'a' appearing in first 
  //word, and alpha_second[1] will give frequency of letter 'b' appearing in
  //second word etc. 

  int alpha_first[26] = {0};
  int alpha_second[26] = {0};
  int i = 0;

  //Calculating frequency of characters in both words

  while (i < strlen(first_word)) {
    alpha_first[first_word[i] - 'a']++;
    i++;
   }

  i = 0;

  while (i < strlen(second_word)) {
    alpha_second[second_word[i] - 'a']++;
    i++;
   }

  //Comparing frequency of characters in both words 

  i = 0;
  
  while (i < 26) {
    if (alpha_first[i] != alpha_second[i]) {
        return 0;
    } else {
        i++;
    }
  }
  
  return 1;
}
