#include "tokenizer.h"

int space_char(char c){

  if(c == ' ' || c == '\t' || c == '\n'){
    return 1;
  }
  return 0;
}

int non_space_char(char c){

  if(c != ' ' || c != '\t' || c != '\n'){
    return 1;
  }
  return 0;
}
