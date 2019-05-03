#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main (int argc, char *argv[]) 
{
  if (argc < 3)
  {
    printf("You are missing arguments");
    return 0;
  }
  else
  {
    printf("The doctor will see you now");
  }
}