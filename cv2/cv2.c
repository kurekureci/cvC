#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SIZE 10

/* funkce - zadano pole pomoci 10 vstupnich parametru 
 * -h = napoveda, -p --> cisla
 * --> spocitat prumer kladnych cisel, prumer zapornych cisel a pocet nul
 */
int cislo[SIZE];

void print_help()
{
  printf("Napoveda:\nNapis -p a pak 10 cisel.\nPrumer z kladnych a zapornych 10 cisel plus pocet nul.\n\n");
}

void uloz(char *a[])
{
  for(int i=0; i<SIZE; i++)
  {
    cislo[i] = atoi (a[i+2]);
  }
}

void zobraz(int *a)
{
  printf("\nZadana cisla jsou: ");
  for(int j=0; j<SIZE; j++)
  {
    printf("%d ",a[j]);
  }
  printf("\n\n");
}

void prum (int *a, int *klad, int *zapor, int *nuly)
{
  int zap = 0;
  int kl = 0;
  int pzap = 0;
  int pkl = 0;
  int nul = 0;
  for(int i=0; i<SIZE; i++)
  {
    if(a[i]==0)
    {
      nul = nul + 1;
    }
    else if(a[i]<0)
    {
      zap = zap + a[i];
      pzap = pzap + 1;
    }
    else if(a[i]>0)
    {
      kl = kl + a[i];
      pkl = pkl + 1;
    }
  }
  
  if(pkl == 0)
  {
   *klad = 0;
  }
  else if(pzap == 0)
  {
   *zapor = 0;
  }
  else
  { 
   *klad = kl/pkl;
   *zapor = zap/pzap;
   *nuly = nul;
  }
}

int main(int argc,char *argv[])
{
  int klad;
  int zapor;
  int nuly;
  
  if(argc<2)
  {
    fprintf(stderr,"Neni zadany parametr -h/-p a cisla.\n");
    return 1;
  }
  else
  {
    if(strcmp(argv[1],"-h") == 0)
    {
      print_help();
    }
    else if((strcmp(argv[1],"-p") ==0) && (argc == 12))
    {
      uloz(argv);
      zobraz(cislo);
      prum (cislo, &klad, &zapor, &nuly);
      printf("Prumer kladnych cisel: %d\nPrumer zapornych cisel: %d\nPocet nul: %d\n\n",klad,zapor,nuly);
    }
    else
    {
      fprintf(stderr,"Nespravne zadane parametry.\n");
      return 2;
    }
  }
  return EXIT_SUCCESS;
}



