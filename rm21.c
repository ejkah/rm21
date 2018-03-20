#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main( void )
{
    printf("You open the door and take a step...\n");
    while(1)
    {
      sleep(4);
      for(i = 0; i<10; i++)
      {
        printf("..............\n");
      }
      printf("YOU FELL INTO A BOTTOMLESS PIT...\n"
    }
}
