#include <stdio.h>
#include "tokenizer.h"
#include <stdlib.h>

/*
Return true (non-zero) if c is a whitespace character
(' ', '\t', or '\n').
Zero terminators are not printable (therefore false)
*/

int space_char(char c){

  if(c == ' ' || c == '\t' || c == '\n'){
    return 1;
  }
  return 0;
}

/*
Return true (non-zero) if c is a non-whitespace
character (not space, tab, or new line).
Zero terminators are not printable (therefore false)
 */

int non_space_char(char c){

  if(c != ' ' && c != '\t' && c != '\n'){
    return 1;
  }
  return 0;
}

/*
Returns a pointer to the first character of the next space-seperated
word in a zero-terminated str. Return a zero pointer if str does not
contain any words.
str is assumed to be pointing to a space character.
 */

char *word_start(char *str){

  char *s = str;

  while(space_char(*s) && *s != '\0'){
    s++;
  }

  if(*s == '\0'){
    return 0;
  }
   return s;
}

/*
Returns a pointer terminator to the first space character or string-
terminator following str in a zero terminates string.
str is assumed to be pointing to a non-space character
 */

char *word_end(char *str){

  char *s = str;
  
  while(non_space_char(*s)){
    s++;
  }
  return s;
}

/*
Counts the number of space seperated words in the string
argument.
 */

int count_words(char *str){

  int counter = 1;

  while(*str != '\0'){
    if(space_char(*str)){
       counter++;
    }
    str++;
  }
  return counter;
}

/*
Returns a freshly allocated zero-terminated string containing
<len> chars from <inStr>
 */

char *copy_str(char *inStr, short len){

  char *new = (char *)malloc(len + 1);
  int i;
  
  for(i = 0; i < len; i++){
    new[i] = inStr[i];
  }

  new[i]= '\0';
  return new;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated
space-seperated tokens from zero-terminated str. */

char **tokenize(char *str){
  int wordCount = count_words(str);
  char **tokens = (char **)malloc(sizeof(char *) * (wordCount + 1));

  char *start;
  char *end;
  int len = 0;
  int counter = 0;

  start = word_start(str);

  while(counter <= count_words(str)){
      end = word_end(start);
      len = end - start;

      tokens[counter] = copy_str(start,len);
      start = word_start(end);

      if(counter == count_words(str)){
	  tokens[counter] = '\0';
	}

	counter++;
    }
      return tokens;
}

/* Prints all tokens */

void print_tokens(char **tokens){
  int t;

  while(tokens[t] != 0){
    printf("%s\n", tokens[t]);
    t++;
  }
}

/* Frees all tokens and the vector containing them. */

void free_tokens(char **tokens){
  int t;

  for(t =0; tokens[t] != 0; t++){
    free(tokens[t]);
  }

  free(tokens);
}
