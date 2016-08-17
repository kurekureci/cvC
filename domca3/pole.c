#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void print_help()
{
  printf("megaobsahla napoveda\n");
}

int main(int argc,char *argv[])
{
  char *domca = "domca";
  char *vstup;
  char buffer[10];
//   char domca[6] = "domca\0";
  printf("%c\n",domca[1]);
  printf("%s\n",domca);
  
  if(argc!=2)
  {
    printf("omg error\n");
    return 1;
  }
  else
  {
    if(strcmp(argv[1],"-help") == 0)
    {
      print_help();
      return 0;
    }
    else
    {
      vstup = argv[1];
      printf("%s\n",vstup);
      if(fgets(buffer, 10, stdin) != 0)
      {
        printf("%s\n", buffer);
      }
    }
  }
  
  return EXIT_SUCCESS;
}
