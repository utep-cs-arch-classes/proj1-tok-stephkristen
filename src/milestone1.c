#include <stdio.h>

/*This is milestone 1. Requiring us to read user
  input & print it back out. */

int main() {

  char input;
  int i = 0;
  char str[i];

  printf(">");

  for(input; (input = getchar()) != '\n'; i++){
      str[i] = input;
      putchar(input);
    }

  printf("\n");	
}
