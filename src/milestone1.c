#include <stdio.h>

int main() {
  printf(">");

  int input;
  input = getchar();

  while(input != EOF){
    putchar(input);
    input = getchar();
  }
}
