/* Trenink dynamicke alokace pameti
 * 0 - int ** table = tabulka čísel - globalni !!
 * 1- zjistit pocet radku a sloupcu tabulky - oddelene funkce
 * 2 - table = malloc(row*sizeof(int*));
 *      for(pocet radku) -->  *  table[i] = malloc(col*sizeof(int));
 * 3 - funkce na poukladani dat do tabulky (pres atoi)
 * 4 - funkce na tisk tabulky
 * !! uvolnit pamet - postupne pozpatku !
 * ./table -print <input.txt */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
//#include <stdbool.h>

#define ROW_SIZE 100

int ** table; //tabulka = pole polí integerů

int countRows(int *numRows) //spocitani radku tabulky
{
  char inputRow[ROW_SIZE];
  *numRows = 0;
  
  while(fgets(inputRow, ROW_SIZE, stdin) != NULL)
  {
    *numRows = *numRows+1;
  }
  
  if(*numRows == 0)
  {
    return 3;
  }
  
  rewind(stdin); //nastavi pozici na zacatek vstupu pro cteni
  return 0;
}

int countCols(int *numCols) //spocitani sloupcu tabulky
{
  char inputRow[ROW_SIZE];
  char *column;
  *numCols = 0;
  fgets(inputRow, ROW_SIZE, stdin);
  column = strtok(inputRow," \t\n");
  
  while(column != NULL)
  {
    *numCols = *numCols+1;
    column = strtok(NULL," \t\n");
  }
  
  if(*numCols == 0)
  {
    return 4;
  }
  
  rewind(stdin); //nastavi pozici na zacatek vstupu pro cteni
  return 0;
}

void allocTable(int numRows, int numCols)
{
  table = malloc(numRows*sizeof(int*));
  
  for(int j=0; j<numRows; j++)
  {
    table[j] = malloc(numCols*sizeof(int));
  }
}

void fillTable(int numRows, int numCols)
{
  char inputRow[ROW_SIZE];
  char * inputCol;
  
  for(int r=0; r<numRows; r++)
  {
    
    if (fgets(inputRow, ROW_SIZE, stdin) != NULL)
    {
      inputCol = strtok(inputRow," \t\n");
      
      for(int s=0; s<numCols; s++)
      {
        table[r][s] = atoi(inputCol);
        inputCol = strtok(NULL," \t\n");
      }
    }
  }
}

void showTable(int numRows, int numCols)
{
  //printf("\n");
  
  for(int r=0; r<numRows; r++)
  {
    
    for(int s=0; s<numCols; s++)
    {
      printf("%i ",table[r][s]);
    }
    
    printf("\n");
  }
}

int main(int argc,char *argv[])
{ 
  int numRows;
  int numCols;
  
  if(argc > 2) //moc vstupnich parametru
  {
    fprintf(stderr,"Too many input parameters.\n");
    return 1;
  } 
  else if(argc < 2) // malo vstupnich parametru
  {
    fprintf(stderr,"Too few input parameters.\n");
    return 2;
  }
  
  if(argc == 2) // ok - vstupnich parametru
  {
    if(countRows(&numRows) != 0)
    {
      fprintf(stderr,"Wrong input.");
      return 3;
    }
    
    fprintf(stderr,"Pocet radku tabulky: %d\n",numRows);
    
    if(countCols(&numCols) != 0)
    {
      fprintf(stderr,"Wrong input.");
      return 4;
    }
    
    fprintf(stderr,"Pocet sloupcu tabulky: %d\n",numCols);
    allocTable(numRows, numCols);
    fillTable(numRows, numCols);
    
    if(strcmp(argv[1],"-print") == 0)
    {
      showTable(numRows, numCols);
    }
    else if(strcmp(argv[1],"-modify") == 0)
    {
      /*
       * zadat souradnice - kontrola platnosti + zadat cislo jako parametr --> jim nahradit misto v tabulce
       * ./table -modify 2 3 <27
       * printnout na stdout
       * (-print <in.txt >out.txt)
       */
    }
    else if(strcmp(argv[1],"-add_row") == 0)
    {
      /* zadat cisla jako parametry, ktera se maji pridat na novy radek - musi jich byt tolik, kolik jich je na radku (kontrola)*/
    }
    else
    {
      fprintf(stderr,"Invalid parameter.\n");
      return 5;
    }
  }
  
  for(int i=0; i<numRows; i++) //postupne uvolnovani pameti
  {
   free(table[i]);
  }
  
  free(table);
  return 0;
}    

