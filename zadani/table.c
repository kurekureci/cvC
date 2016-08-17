#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define ROW_SIZE 100

char row[ROW_SIZE];

int gainRow(int requiredRow) 
{
  int countRow = 1; //pro cykleni - radky
  bool isFoundRow = false; //boolean pro znaceni nalezeni radku
  
  if(requiredRow <= 0)
  {
    return 4;
  }
  
  while (gets(row) && countRow <= requiredRow) //pokud je jeste radek a je mensi/roven hledanemu
  {
    
    if(countRow == requiredRow)
    {
      isFoundRow = true;
      break; //kdyz dojde k hledanemu radku, ukonci se cyklus
    }
    else
    {
      countRow++;
    }
  }
  
  if (!isFoundRow)
  {
    return 4;
  }
  else
  {
    return 0;
  }
}

int gainWord(int requiredCol, char **word)
{
  int countCol = 1; //pro cykleni - sloupce
  bool isFoundCol = false; //boolean pro znaceni nalezeni sloupce
  char *words;
  words = strtok (row," \t\n"); //parsovani - rozdeleni stringu na useky podle zadanych oddelovacich znaku
  
  while (words != NULL && countCol <= requiredCol) //pokud je jeste radek a je mensi/roven hledanemu
  {
    
    if(countCol == requiredCol)
    {
      *word = words;
      isFoundCol = true;
      break; //kdyz dojde k hledanemu slovu, ukonci se cyklus
    }
    else
    {
      countCol++;
      words = strtok (NULL," \t\n");
    }
  }
  
  if (!isFoundCol)
  {
    return 4;
  }
  else
  {
    return 0;
  }
}

int main(int argc,char *argv[])
{
  char *word; //retezec s danym slovem
  
  if(argc > 4) //moc vstupnich parametru
  {
    fprintf(stderr,"Too many input parameters.\n");
    return 1;
  } 
  else if(argc < 4) // malo vstupnich parametru
  {
    fprintf(stderr,"Too few input parameters.\n");
    return 2;
  }
  
  if(argc == 4) // ok - vstupnich parametru
  {
    
    if(strcmp(argv[1],"-show") == 0)
    {
      if(gainRow(atoi(argv[2])) != 0)
      {
        fprintf(stderr,"Out of table range.\n");
        return 4;
      }
      
      if(gainWord(atoi(argv[3]), &word) != 0)
      {
        fprintf(stderr,"Out of table range.\n");
        return 4;
      }

      printf("%s\n", word);
      return 0;
    }
  }
}    

/* zjistit pocet radku a sloupcu tabulky - oddelene funkce !
  * int ** table = tabulka čísel - globalni !!
 * table = malloc(row*sizeof(int*));
 * for(pocet radku) -->  *  table[i] = malloc(col*sizeof(int));
 * funkce na poukladani dat do tabulky (pres atoi)
 * funkce na tisk tabulky
 * 
 * jina fce nez gets?
 * scanf --> strtok na radky --> na sloupce
 * 
 * uvolnit pamet - postupne pozpatku !
 * ./table -print <input.txt