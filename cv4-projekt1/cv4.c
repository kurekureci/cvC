#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void print_help()
{
  printf("Popis parametru:\n"
  "  --help    Vypise tuto obrazovku s napovedou.\n"
  "  -t        Nejvyssi zobrazena jednotka bude tyden.\n"
  "            Parametr -t znamena totez, co spusteni bez parametru.\n"
  "  -d        Nejvyssi zobrazena jednotka bude den.\n"
  "  -h        Nejvyssi zobrazena jednotka bude hodina.\n"
  "  -m        Nejvyssi zobrazena jednotka bude minuta.\n"
  "  -s        Nejvyssi zobrazena jednotka bude sekunda.\n\n"
  "Priklad pouziti:\n"
  "  Pri zadani parametru proj1 -m\n"
  "  Program ocekava ciselny udaj v sekundach na standardnim vstupu.\n"
  "  Tento udaj pote prevede na udaj v minutach.\n"
  "  Napriklad zadate-li 4206, tak vysledek, ktery program vytiskne\n"
  "  bude 70 minut 6 sekund.\n\n");
}

void uloz (unsigned long *x)
{
  char buffer[128];
  if(fgets(buffer, 128, stdin) != 0)
  {
    *x = atol(buffer);
    printf("Zadane cislo %lu\n", *x); 
  }
}

void min (unsigned long x, unsigned long *m, unsigned long *s)
{
  *m = x/60;
  *s = x%60;
}
void hod (unsigned long x, unsigned long *h, unsigned long *zb)
{
  *h = x/3600;
  *zb = x%3600;
}

void den (unsigned long x, unsigned long *d, unsigned long *zb)
{
  *d = x/86400;
  *zb = x%86400;
}

void tyd (unsigned long x, unsigned long *t, unsigned long *zb)
{
  *t = x/604800;
  *zb = x%604800;
}

void tiskT (unsigned long t)
{
  if(t==1)
  {
    printf("%lu tyden\n", t);
  }
  else if((t>=2) && (t<=4))
  {
    printf("%lu tydny\n", t);
  }
  else 
  {
    printf("%lu tydnu\n", t);
  }
}

void tiskD (unsigned long d)
{
  if(d==1)
  {
    printf("%lu den\n", d);
  }
  else if((d>=2) && (d<=4))
  {
    printf("%lu dny\n", d);
  }
  else 
  {
    printf("%lu dnu\n", d);
  }
}

void tiskH (unsigned long h)
{
  if(h==1)
  {
    printf("%lu hodina\n", h);
  }
  else if((h>=2) && (h<=4))
  {
    printf("%lu hodiny\n", h);
  }
  else 
  {
    printf("%lu hodin\n", h);
  }
}

void tiskM (unsigned long m)
{
  if(m==1)
  {
    printf("%lu minuta\n", m);
  }
  else if((m>=2) && (m<=4))
  {
    printf("%lu minuty\n", m);
  }
  else 
  {
    printf("%lu minut\n", m);
  }
}

void tiskS (unsigned long s)
{
  if(s==1)
  {
    printf("%lu sekunda\n", s);
  }
  else if((s>=2) && (s<=4))
  {
    printf("%lu sekundy\n", s);
  }
  else 
  {
    printf("%lu sekund\n", s);
  }
}

int main(int argc,char *argv[])
{
  unsigned long x;
  unsigned long s;
  unsigned long m;
  unsigned long h;
  unsigned long d;
  unsigned long t;
  unsigned long zb1;
  unsigned long zb2;
  unsigned long zb3;
  if(argc>2)
  {
    fprintf(stderr,"Zadano vic nez 1 parametr.\n");
    return 1;
  }
  else if((argc==2)&&(strcmp("--help",argv[1])==0))
  {
    print_help();
    return 0;
  }
  else if((argc<2) || (strcmp("-t",argv[1])==0) || (strcmp("-d",argv[1])==0) || (strcmp("-h",argv[1])==0) || (strcmp("-m",argv[1])==0) || (strcmp("-s",argv[1])==0))
  {
    uloz(&x);
    
    if((argc<2) || (strcmp("-t",argv[1])==0))
    {
      tyd(x,&t,&zb1);
      den(zb1,&d,&zb2);
      hod(zb2,&h,&zb3);
      min(zb3,&m,&s);      
      printf("Vyjadreno az po tydny:\n"); 
      tiskT(t);
      tiskD(d);
      tiskH(h);
      tiskM(m);
      tiskS(s);
    }
    else if(strcmp("-d",argv[1])==0)
    {
      den(x,&d,&zb2);
      hod(zb2,&h,&zb3);
      min(zb3,&m,&s);      
      printf("Vyjadreno az po dny:\n");
      tiskD(d);
      tiskH(h);
      tiskM(m);
      tiskS(s);
    }
    else if(strcmp("-h",argv[1])==0)
    {
      hod(x,&h,&zb3);
      min(zb3,&m,&s);      
      printf("Vyjadreno az po hodiny:\n"); 
      tiskH(h);
      tiskM(m);
      tiskS(s);
    }
    else if(strcmp("-m",argv[1])==0)
    {
      min(x,&m,&s);      
      printf("Vyjadreno az po minuty:\n"); 
      tiskM(m);
      tiskS(s); 
    }
    else if(strcmp("-s",argv[1])==0)
    {
    printf("Vyjadreno az po sekundy:\n");
    tiskS(x);
    }
  }
  else
  {
    fprintf(stderr,"Spatne zadany parametr.\n");
    return 1;
  }
  return 0;
}
