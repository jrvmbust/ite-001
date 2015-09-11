#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>
int a,b;
main ()
{
	
  //init rand seed
  srand(time(NULL));
  //actual rand num
  b = rand() % 100 + 1;
	puts("\tGUESS THE NUMBER\n      --------------------");
    while (b!=a){

    printf ("Guess the number (1 to 100): ");
    scanf ("%d",&a);
    if (b<a) {
	printf ("--------------------------\nThe secret number is lower\n---------------------------\n");
    }
	else if (b>a) {
	printf ("--------------------------\nThe secret number is higher\n--------------------------\n");
  }
}
  printf ("Congratulations!");

}
