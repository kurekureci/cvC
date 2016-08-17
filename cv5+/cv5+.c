#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define ASCII 48

/* 3 soubory ve stejne slozce jak program: cislo1.txt, cislo2.txt, vystup.txt
 * v kazdem souboru bude 1 integer
 * 1 parametr: + - * / --> podle toho se ty cisla poscitaji/atd... 
 * vystup na desetinna mista
 * bez pouziti funkce atoi :/
 */

int prevod(FILE *soubor)
{
  char znak;
  int cislo;
  int result = 0;
  while(((znak = fgetc(soubor)) != '\n') && (znak != EOF)) 
  {
    printf("%c\n",znak);
    if((znak<='9') && (znak>='0'))
    {
      cislo = znak - ASCII;
      result = result*10 + cislo;
    }
    else
    {
      fprintf(stderr,"Je zadany jiny znak nez cislo.\n");
    }
      
  }
  return result;
}

int main(int argc,char *argv[])
{
  FILE *cislo1;
  FILE *cislo2;
  FILE *vystup;
  int cis1 = 0;
  int cis2 = 0;
  double vysledek;
  int times = 10;
    
  cislo1 = fopen("cislo1.txt","r");
  cislo2 = fopen("cislo2.txt","r");
  vystup = fopen("vystup.txt","a");
  
  if((cislo1 == NULL) || (cislo2 == NULL))
  {
    fprintf(stderr,"Soubor nelze otevrit.\n");
    return 1;
  }
  else
  {
    cis1 = prevod(cislo1);
    cis2 = prevod(cislo2);
    printf("1. cislo: %d\n2.cislo: %d\n",cis1,cis2);
    /*if(fgets(c1,5,cislo1)!=NULL)
    {
      printf("1. cislo: %s\n",c1);
      //ci1 = atoi(c1);
      ci1[0]=c1[0]-ASCII;
      for(int i=1;i<4;i++)
      {
        ci1[i] = c1[i]-ASCII;
        if(ci1[i]<times)
        {
          for(int j=0;j<i;j++)
          {
            ci1[j]=ci1[j]*times;
          }
        }
      }
      for(int k=0;k<4;k++)
      {
      cis1 = cis1 + ci1[k];
      }  
      printf("--> %d\n",cis1);
    }
    else
    {
      fprintf(stderr,"V souboru cislo1 neni nic napsano.\n");
      return 2;
    }
    
    
    if(fgets(c2,5,cislo2)!=NULL)
    {
      printf("2. cislo: %s\n",c2);
      //ci2 = atoi(c2);
      //ci2[0] = c2[0]-ASCII;
      //printf("--> %d\n",ci2);
    }
    else
    {
      fprintf(stderr,"V souboru cislo 2 neni nic napsano.\n");
      return 2;
    }*/
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
    vysledek = cis1+cis2;
    if(vystup!=NULL)
    {
      fprintf(vystup,"Vysledek scitani: %f\n",vysledek);
      fclose(vystup);
    }
  }  
  else if((argc==2) && (strcmp(argv[1],"-") == 0))
  {
    vysledek = cis1-cis2;
    if(vystup!=NULL)
    {
      fprintf(vystup,"Vysledek odcitani: %f\n",vysledek);
      fclose(vystup);
    }
  }  
  else if((argc==2) && (strcmp(argv[1],"*") == 0))
  {
    vysledek = cis1*cis2;
    if(vystup!=NULL)
    {
      fprintf(vystup,"Vysledek nasobeni: %f\n",vysledek);
      fclose(vystup);
    }
  }  
  else if((argc==2) && (strcmp(argv[1],"/") == 0))
  {
    vysledek = cis1/cis2;
    if(vystup!=NULL)
    {
      fprintf(vystup,"Vysledek deleni: %f\n",vysledek);
      fclose(vystup);
    }
  }  
  else
  {
    fprintf(stderr,"Spatne zadany parametr.\n");
    return 4;
  }
  
  return 0;
}
