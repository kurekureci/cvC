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
  fprintf(stderr,"Pocet radku: %i \n",numRows);
  fprintf(stderr,"Pocet sloupcu: %i \n",numCols);
  
  for(int r=0; r<numRows; r++)
  {
    
    for(int s=0; s<numCols; s++)
    {
      printf("%i ",table[r][s]);
    }
    
    printf("\n");
  }
}

int modifTable(int rowPosition, int colPosition, int newNumber, int numRows, int numCols) //prepise cislo v tabulce na dane pozici
{
  
  if(rowPosition <= 0 || colPosition <= 0 || rowPosition > numRows || colPosition > numCols)
  {
    return 1;
  }
  
  table[rowPosition-1][colPosition-1] = newNumber;
  return 0;
}

void addRow(char ** parameters, int *numRows,int numCols, int start)
{
  int lastRow;
  
  *numRows = *numRows + 1;
  lastRow = *numRows;
  table = (int**)realloc(table, lastRow*sizeof(int*));
  table[lastRow-1] = malloc(numCols*sizeof(int));
  
  for(int i=0; i<numCols; i++)
  {
    table[lastRow-1][i] = atoi(parameters[i+start]);
  }
}

void addCol(char ** parameters, int numRows,int *numCols)
{
  int lastCol;
  
  *numCols = *numCols + 1;
  lastCol = *numCols;
  
  for(int r=0; r<numRows; r++)
  {
    table[r] = realloc(table[r],lastCol*sizeof(int));
    table[r][lastCol-1] = atoi(parameters[r+2]);
  }
}

int addRowAt(char ** parameters,int numRows,int numCols) //po pridani radku na konec tabulky ho "presune" na dane misto
{
  int pomRow[numCols]; //pomocny radek
  int position = atoi(parameters[2])-1; //pozice radku, kam ma prijit pridany radek (ted posledni)
  
  if(position > (numRows-1) || position < 0)
  {
    return 10;
  }
  
  for(int i = 0; i<numCols; i++) //ulozeni noveho posledniho radku do pomocne promenne
  {
    pomRow[i] = table[numRows-1][i];
  }
  
  for(int r = (numRows-1); r>=position; r--) //presouvani radku v tabulce
  {
    
    for(int s = 0; s<numCols; s++) // indexovani sloupcu
    {
      
      if(r>position) //presouvani radku
      {
        table[r][s] = table[r-1][s];
      }
      else //doplneni radku na dane pozici - ulozenym pomocnym rakdem
      {
        table[r][s] = pomRow[s];
      }
    }
  }
  
  return 0;
}

int removeRows(char ** parameters, int numParameters, int *numRows,int numCols) // !! opravit pro vic radku
{
  int numRemoveRow[numParameters-2]; //pro pozice radku ke smazani
  int rowPosition;
  
  for(int i=0; i<(numParameters-2); i++)
  {
    numRemoveRow[i] = (atoi(parameters[i+2])-1); //ukladani pozic radku ke smazani
    
    if(numRemoveRow[i] < 0 || numRemoveRow[i] > (*numRows-1))
    {
      return 1;
    }
  }
  
  for(int j=0; j<(numParameters-2); j++)
  {
    rowPosition = numRemoveRow[j];
    
    for(int r = rowPosition; r<(*numRows-1);r++)
    {
      
      for(int s = 0; s<numCols; s++)
      {
        table[r][s] = table[r+1][s];
      }
    }
    
    free(table[(*numRows-1)]);
    *numRows = *numRows - 1;
    table = (int**)realloc(table,*numRows*sizeof(int*));
  
    for(int k=j; k<(numParameters-3); k++)
    {
      
      if(numRemoveRow[k] < numRemoveRow[k+1])
      {
        numRemoveRow[k+1] = numRemoveRow[k+1]-1;
      }
      else
      {
        return 1;
      }
    }
  }
    
  return 0;
}

int removeCols(char ** parameters, int numParameters, int numRows,int *numCols) // !! opravit pro vic sloupcu
{
  int numRemoveCol[numParameters-2];
  int colPosition;
  
  for(int i=0; i<(numParameters-2); i++)
  {
    numRemoveCol[i] = (atoi(parameters[i+2])-1); //ukladani pozic radku ke smazani
    
    if(numRemoveCol[i] < 0 || numRemoveCol[i] > (*numCols-1))
    {
      return 1;
    }
  }
  
  for(int j=0; j<(numParameters-2); j++)
  {
    colPosition = numRemoveCol[j];
    
    for(int r = 0; r<(numRows);r++)
    {
      
      for(int s = colPosition; s<(*numCols-1); s++)
      {
        table[r][s] = table[r][s+1];
      }
      
      table[r] = (int*)realloc(table[r],(*numCols-1)*sizeof(int));
    }
    
    *numCols = *numCols - 1;
    
    for(int k=j; k<(numParameters-3); k++)
    {
      
      if(numRemoveCol[k] < numRemoveCol[k+1])
      {
        numRemoveCol[k+1] = numRemoveCol[k+1]-1;
      }
      else
      {
        return 1;
      }
    }
  }
  
  return 0;
}

int main(int argc,char *argv[])
{ 
  int numRows;
  int numCols;
  
  if(argc < 2) // malo vstupnich parametru
  {
    fprintf(stderr,"Too few input parameters.\n");
    return 2;
  }
  else if (argc >= 2) // ok - vstupnich parametru
  {
    if(countRows(&numRows) != 0)
    {
      fprintf(stderr,"Wrong input.");
      return 3;
    }
    
    if(countCols(&numCols) != 0)
    {
      fprintf(stderr,"Wrong input.");
      return 4;
    }
    
    allocTable(numRows, numCols);
    fillTable(numRows, numCols);
    
    if(strcmp(argv[1],"-print") == 0)
    {
      showTable(numRows, numCols);
    }
    else if(strcmp(argv[1],"-modify") == 0)
    {
      
      if(argc != 5)
      {
        fprintf(stderr,"Invalid parameters: -modify needs 3 numbers.\n");
        return 6;
      }
      
      if(modifTable(atoi(argv[2]),atoi(argv[3]),atoi(argv[4]),numRows,numCols) != 0)
      {
        fprintf(stderr,"Invalid parameters: -modify needs 3 numbers.\n");
        return 6;
      }
      
      showTable(numRows, numCols);
    }
    else if(strcmp(argv[1],"-add_row") == 0)
    {
        
      if(argc != (2+numCols)) // pocet zadanych cisel se musi rovnat poctu sloupcu
      {
        fprintf(stderr,"Too many/few parameters: -add_row needs %i numbers.\n", numCols);
        return 7;
      }
      
      addRow(argv,&numRows,numCols,2);
      showTable(numRows,numCols);
    }
    else if(strcmp(argv[1],"-add_col") == 0)
    {
      
      if(argc != (2+numRows)) // pocet zadanych cisel se musi rovnat poctu radku
      {
        fprintf(stderr,"Too many/few parameters: -add_col needs %i numbers.\n", numRows);
        return 8;
      }
      
      addCol(argv,numRows,&numCols);
      showTable(numRows,numCols);
    }
    else if(strcmp(argv[1],"-add_row_at") == 0)
    {
      
      if(argc != (3+numCols)) // pocet zadanych cisel se musi rovnat poctu sloupcu + cislo pro pozici radku
      {
        fprintf(stderr,"Too many/few parameters: -add_row_at needs number od row and %i numbers.\n", numCols);
        return 9;
      }
      
      addRow(argv,&numRows,numCols,3); // nejprve se prida zadany radek nakonec
            
      if(addRowAt(argv,numRows,numCols) != 0) // pak se tabulka presklada dle zadane pozice 
      {
        fprintf(stderr,"Invalid input position (0 < position <= %i).\n", numRows);
        return 10;
      }
      
      showTable(numRows,numCols);
    }
    else if(strcmp(argv[1],"-remove_rows") == 0)
    {
      
      if(argc < 3 || argc >(2+numRows)) 
      {
        fprintf(stderr,"Too many/few parameters (2 < parameters <= %i).\n", (numRows+2));
        return 11;
      }
      
      if(removeRows(argv,argc,&numRows,numCols) != 0)
      {
        fprintf(stderr,"Invalid input parameters in -remove_rows - ascending numbers of rows needed (0 < nuber of rows <= %i).\n", (numRows));
        return 12;
      }
      
      showTable(numRows,numCols);
    }
    else if(strcmp(argv[1],"-remove_cols") == 0)
    {
      
      if(argc < 3 || argc >(2+numCols)) 
      {
        fprintf(stderr,"Too many/few parameters (2 < parameters <= %i).\n", (numCols+2));
        return 13;
      }
      
      if(removeCols(argv,argc,numRows,&numCols) != 0)
      {
        fprintf(stderr,"Invalid input parameters in -remove_cols - ascending numbers of columns needed (0 < number of columns <= %i).\n", (numCols));
        return 14;
      }
      
      showTable(numRows,numCols);
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