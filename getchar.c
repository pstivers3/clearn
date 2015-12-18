#include <stdio.h>

// echos whatever is typed on the command line
// ctrl-c or ctrl-d to exit

int main(void){

  int c;

  while ((c = getchar()) != EOF){    
    if (c == '\n'){
      printf("\n"); 
    } else{
      putchar(c);
    }  
  }
  return 0;
}
