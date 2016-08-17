#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


/* 3 soubory ve stejne slozce jak program: cislo1.txt, cislo2.txt, vystup.txt
 * v kazdem souboru bude 1 integer
 * 1 parametr: + - * / --> podle toho se ty cisla poscitaji/atd... 
 
 */

int main(int argc,char *argv[])
{
  FILE *cislo1;
  FILE *cislo2;
  FILE *vystup;
  char c1[5];
  char c2[5];
  int ci1;
  int ci2;
  int vysledek;
    
  cislo1 = fopen("cislo1.txt","r");
  cislo2 = fopen("cislo2.txt","r");
  vystup = fopen("vystup.txt","w");
  
  if((cislo1 == NULL) || (cislo2 == NULL))
  {
    fprintf(stderr,"Soubor nelze otevrit.\n");
    return 1;
  }
  else
  {
    if(fgets(c1,5,cislo1)!=NULL)
    {
      printf("1. cislo: %s\n",c1);
      ci1 = atoi(c1);
    }
    else
    {
      fprintf(stderr,"V souboru cislo1 neni nic napsano.\n");
      return 2;
    }
    
    if(fgets(c2,5,cislo2)!=NULL)
    {
      printf("2. cislo: %s\n",c2);
      ci2 = atoi(c2);
    }
    else
    {
      fprintf(stderr,"V souboru cislo 2 neni nic napsano.\n");
      return 2;
    }
  }
  
  fclose(cislo1);
  fclose(cislo2);
  
  if(argc>2)
  {
    fprintf(stderr,"Zadano moc parametru.\n");
    return 3;
  }
  else if((argc==2) && (strcmp(argv[1],"+") == 0))
  {
    vysledek = ci1+ci2;
    if(vystup!=NULL)
    {
      fprintf(vystup,"Vysledek scitani: %d",vysledek);
    }
    /*else
    {
      printf("OMG WTF DPC UZ!!\n");
    }*/
  }  
  else if((argc==2) && (strcmp(argv[1],"-") == 0))
  {
    vysledek = ci1-ci2;
    if(vystup!=NULL)
    {
      fprintf(vystup,"Vysledek odcitani: %d",vysledek);
    }
  }  
  else if((argc==2) && (strcmp(argv[1],"*") == 0))
  {
    vysledek = ci1*ci2;
    if(vystup!=NULL)
    {
      fprintf(vystup,"Vysledek nasobeni: %d",vysledek);
    }
  }  
  else if((argc==2) && (strcmp(argv[1],"/") == 0))
  {
    vysledek = ci1/ci2;
    if(vystup!=NULL)
    {
      fprintf(vystup,"Vysledek deleni: %d",vysledek);
    }
  }  
  else
  {
    fprintf(stderr,"Spatne zadany parametr.\n");
    return 4;
  }
  
  return 0;
}
