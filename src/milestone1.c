#include <stdio.h>
#define LIMIT 50

/*This is milestone 1. Requiring us to read user
  input & print it back out. */

int main() {

  char str[LIMIT];

  printf(">");
  scanf("%[^\n]s", str);
  printf("\n %s \n", str);
  
}
