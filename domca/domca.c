#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int secti(int a, int b)
{
  int result;
  
  result = a + b;
  return result;
}

int forek (int e, int d, int f)
{
  int result;
  result = e + d - f;
  return result;
}

/*
 * HLAVNI PROGRAM
 */
int main(int argc,char *argv[])
{
  int cislo1 = 5;
  int cislo2 = -6;
  int cislo3 = 2;
  int result;
  result = forek(cislo1, cislo2, cislo3);
  printf("Vysledek je tentononc: %d \n", result);
  return EXIT_SUCCESS;
}

