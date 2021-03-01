#include <stdio.h>
#include "tokenizer.h"

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
  return --s;
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
