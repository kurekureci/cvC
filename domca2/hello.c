#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int cosi (int a)
{
  int result = 0;
  for(int i=0; i<20; i++)
  {
    result = result + a;
  }
  return result;
}

void hvezdy (void)
{
  for(int i=0; i<10; i++)
  {
    for (int j=0; j<=i; j++)
      printf("*");
    printf("\n");  
  }
}

void iritec (void)
{
  for(int i=10; i>0; i--)
  {
    for(int j=0; j<i; j++)
    {
      printf("*");
    }
    printf("\n");
  }
}

void cahoun (void)
{
  for(int i=5; i>0; i--)
  {
    for(int j=0; j<i-1; j++)
      printf(" ");
    printf("*");
    for(int l=0; l<5-i; l++)
      printf("**");
    printf("\n");  
  }
}


int main(int argc,char *argv[])
{
  int cislo = 2;
  int vysledek;
  hvezdy();
  vysledek = cosi(cislo);
  cahoun();
  printf("Hello world \nAhoj Míšo \nVysledek je %d \n", vysledek);
  iritec();
  return EXIT_SUCCESS;
}
