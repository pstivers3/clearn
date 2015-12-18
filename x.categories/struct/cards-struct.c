#include <stdio.h>


typedef struct card{
  int num;
  char *suite;
} card;

card c[52], bomb = {0, "Joker"};

void num1(card []);

main()
{
  
  int i;

  for (i=0; i<10; i++)
  {
    c[i].num = i;
    switch (i%4)
    { 
      case 0: c[i].suite = "spades";
              break;
      case 1: c[i].suite = "diamonds";
              break;
      case 2: c[i].suite = "hearts";
              break;
      default: c[i].suite = "clubs";
    }
		
   printf("Card c[%d] is %d of %s\n", i, c[i].num, (c+i)->suite);
		
  }
	

/*	
  bomb.num = 0;
  bomb.suite = "Joker"; */
  printf("Card 'bomb' is %d of %s\n", bomb.num, bomb.suite);

  num1(c);

  return 0;
}

void num1(card k[])
{
  printf("%d\n", k[2].num);
}

