#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SIZE 5

/* Zadani:
 * novy program: datovy typ struktura: osoba - polozky: jmeno (string), prijmeni (chain), plat (int), datum_nar (struct - den, mesic, rok)
 * pole nad datovym typem osoba velikosti 5 - naplnit daty o osobach (rucne v kodu)
 * --> funkce na vypsani prijmeni a roku narozeni vsech osob, ktere maji plat vyssi nez 20 000 */
struct Osoba
{
  char jmeno[20];
  char prijmeni[20];
  int plat;
  struct datum_nar
  {
    int den;
    char mesic[10];
    int rok;
  }dat;
};

/*void vypis(struct Osoba Osoba[SIZE-1]) //vypise vsechny ve strukture
{
  for(int i=0;i<SIZE;i++)
  {
    printf("\nOsoba: %s %s\nNarozen: %d %s %d\nPlat: %d\n\n",Osoba[i].jmeno,Osoba[i].prijmeni,Osoba[i].dat.den,Osoba[i].dat.mesic,Osoba[i].dat.rok,Osoba[i].plat);
  }
}*/

void plat(struct Osoba Osoba[SIZE])
{
  int a = 0;
  printf("\nPlat nad 20 tisic:\n");
  for(int i=0;i<SIZE;i++)
  {
    if(Osoba[i].plat>=20000)
    {
      printf("%s %s     %d %s %d\n",Osoba[i].jmeno,Osoba[i].prijmeni,Osoba[i].dat.den,Osoba[i].dat.mesic,Osoba[i].dat.rok);
      a = a+1;
    }
  }
  if(a==0) 
  {
    printf("- v databázi nikdo nenalezen.\n");
  }
  printf("\n");
}

int main(int argc,char *argv[])
{
  struct Osoba Osoba[SIZE];
  strcpy(Osoba[0].jmeno, "Michal");
  strcpy(Osoba[0].prijmeni, "Malanik");
  Osoba[0].plat = 1000000;
  Osoba[0].dat.den = 27;
  strcpy(Osoba[0].dat.mesic, "unor");
  Osoba[0].dat.rok = 1992;
  
  strcpy(Osoba[1].jmeno, "Doubravka");
  strcpy(Osoba[1].prijmeni, "Eherembergerova");
  Osoba[1].plat = 8000;
  Osoba[1].dat.den = 15;
  strcpy(Osoba[1].dat.mesic, "duben");
  Osoba[1].dat.rok = 1980;
  
  strcpy(Osoba[2].jmeno, "Oldřiška");
  strcpy(Osoba[2].prijmeni, "Ficova");
  Osoba[2].plat = 25000;
  Osoba[2].dat.den = 3;
  strcpy(Osoba[2].dat.mesic, "leden");
  Osoba[2].dat.rok = 1959;
  
  strcpy(Osoba[3].jmeno, "Vilibald");
  strcpy(Osoba[3].prijmeni, "Klatil");
  Osoba[3].plat = 14000;
  Osoba[3].dat.den = 22;
  strcpy(Osoba[3].dat.mesic, "cerven");
  Osoba[3].dat.rok = 1966;
  
  strcpy(Osoba[4].jmeno, "Marcela");
  strcpy(Osoba[4].prijmeni, "Parcela");
  Osoba[4].plat = 28000;
  Osoba[4].dat.den = 18;
  strcpy(Osoba[4].dat.mesic, "rijen");
  Osoba[4].dat.rok = 1989;
  
  //vypis(Osoba);
  plat(Osoba);
  return EXIT_SUCCESS;
}

