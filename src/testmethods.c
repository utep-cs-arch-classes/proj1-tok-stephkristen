#include <stdio.h>
#include "tokenizer.h"
#define LIMIT 100

int main(){

  /* Created 2 characters with spaces to test space_char
     and non_space_char methods */
  
  char x = ' ';
  char z = ' ';
  
  printf("%d\n", space_char(x));
  printf("%d\n", non_space_char(z));

  /* Creating array of 100 chars to take user input & test methods
     word_start, word_end and count_words */
  
  char arr[LIMIT];

  char input;
  int i = 0;

  for(i = 0; (input = getchar()) != '\n' && i< LIMIT -1; i++){

      arr[i] = input;
    }

      arr[i] = '\0';
  
      char *startPointer = word_start(arr);
      printf("Word start: %c\n", *startPointer);

      char *endPointer = word_end(arr);
      printf("Word end: %c\n", *endPointer);

      int numOfWords = count_words(arr);
      printf("Number of words: %d\n", numOfWords);
}
