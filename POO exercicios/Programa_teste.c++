#include <stdio.h>

int main()
{
  int x;
  int *ptr;
  x = 5;
  ptr = &x;
  printf("O valor da variavel X e: %d\n", *ptr);  // derreferenciando um ponteiro

  
  *ptr = 10;  // usando derreferencia no "lado esquerdo" de uma atribuição
  printf("Agora, X vale: %d\n", *ptr);
}