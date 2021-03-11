#include <stdio.h>
#include "tokenizer.h"
#define LIMIT 100

int main(){

  /* Created 2 characters with spaces to test space_char
     and non_space_char methods */
  
  char x = ' ';
  char z = ' ';
  
  // printf("%d\n", space_char(x));
  // printf("%d\n", non_space_char(z));

  /* Creating array of 100 chars to take user input & test methods
     word_start, word_end and count_words */
  
  char arr[LIMIT];

  char input;
  int i = 0;

  printf("Hello welcome. In this program you will be asked to input a string to be tokenized.\n");
  printf("\nYou can print the history of your inputs by inputting \"*\". \n");
  printf("You can input \"!\" and the number of the index from history you would like to print.\n");
  printf("You can input \"#\" to exit the program.\n");
  printf("Now enter the string to be tokenized: \n");

  while(*arr != '#') {
  printf("$");

  for(i = 0; (input = getchar()) != '\n' && i< LIMIT -1; i++){

      arr[i] = input;
    }

      arr[i] = '\0';

      if(*arr != '#' && *arr != '!'){
  
      char *startPointer = word_start(arr);
      // printf("Word start: %c\n", *startPointer);

      char *endPointer = word_end(arr);
      // printf("Word end: %c\n", *endPointer);

      int numOfWords = count_words(arr);
      printf("Number of words: %d\n", numOfWords);

      char *copyString = copy_str(arr, 4);
      // printf("Copied string: %s\n", copyString);

      char *pointer = arr;
      char **tokenizer = tokenize(arr);

      printf("After tokenized: \n");
      print_tokens(tokenizer);            //Prints all tokens
      
      }

      if(*arr == '!'){
	printf("l");               //Will print token from history at given index
      }

      if(*arr == '*'){
	printf("h");               //Will print entire history of tokens
      }
  }

  printf("History will now be cleaned. Goodbye.\n");
}
