#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SIZE 5 //textova zamena, nezabere nic v pameti narozdil od globalni promenne
/* Zadani:
- zpracovavat 5 parametru - cela cisla, kontrola poctu parametru, -h tisk napovedy, -p nasledovat bude 5 cisel - ulozit do polea tisk pole 
- vytisknout prumernou  a nejvetsi hodnotu pole */

int parametr[SIZE]; //globalni promenna

void print_help()
{
  printf("Napoveda:\nUlozi se 5 celych cisel, jupi!\n\n");
}

void uloz(char *a[])
{
  for(int i=0; i<SIZE; i++)
  {
    parametr[i] = atoi (a[i+2]);
  }
}

void zobraz(int* a)
{
  for(int j=0; j<SIZE; j++)
  {
    printf("%d\n",a[j]);
  }
  printf("\n");
}

int prum (int* p)
{
  int vysl;
  int soucet = 0;
  for(int i=0; i<SIZE; i++)
  {
    soucet=soucet+p[i];
  }
  vysl = soucet/SIZE;
  return vysl;
}

void max (int *m, int *mezi, int *ind)
{
  *mezi = m[0];//ulozi se tam kam ukazuje ukazatel *mezi, dereference
  *ind = 0;
  for(int i=1; i<SIZE; i++)
  {
    if(m[i]>(*mezi))
    {
      *ind = i;
      *mezi = m[i];
    }
  }
}

int main(int argc,char *argv[])
{
  int prumer;
  int maximum;
  int ind;
  if(argc<2)
  {
    fprintf(stderr,"Omg zadej parametr.\n"); //vystup na stderr
    return 1;
  }
  else
  {
    if(strcmp(argv[1],"-h") == 0)
    {
      print_help();
      return 0;
    }
    else if((strcmp(argv[1],"-p") == 0) && (argc==SIZE+2))
    {
      uloz(argv);
      printf("\nZadana cisla:\n");
      zobraz(parametr);
      prumer = prum(parametr);
      printf("Prumerna hodnota: %d\n", prumer);
      max(parametr,&maximum,&ind);//reference, zadani adres pro vystup funkce
      printf("Maximalni hodnota: %d\nIndex maxima: %d\n", maximum, ind);
    }
    else
    {
      fprintf(stderr,"Spatne zadany parametr.\n"); //vystup na stderr
      return 1;
    }
  }
  return EXIT_SUCCESS;
}