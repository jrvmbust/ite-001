#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>
int game();
int main();
char again;
int a,b;



int game()
{
	
  //init rand seed 
  srand(time(NULL));
  //actual rand num
  b = rand() % 100;
  
	printf("---------------------------------\n\tGUESS THE NUMBER\n---------------------------------\n");
    while (b!=a){

    printf ("Guess the number (0 to 100): ");
    scanf ("%d",&a);
    if (b<a) {
	printf ("--------------------------\nThe secret number is lower\n---------------------------\n");
    }
	else if (b>a) {
	printf ("--------------------------\nThe secret number is higher\n--------------------------\n");
  }
}
  printf ("\n------------------------------\n\tCongratulations!\n------------------------------");
  printf("\n\nPlay Again? (Y/N): ");scanf("%s",&again);
  if (again=='Y'||again=='y')
  {
  	return main();
  }
  else if(again=='n'||again=='N')
  {
  	return 0;
  }

}


int main()
{
	game();
	return 0;
}
