//rvargas

#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>
#include <string.h>
int main(), goback(), Mgame();
int randnum,inp;
char inpd[10];


int goback()
{
  char again;	  
  printf("\n\nPlay Again? (Y/N): "); scanf("%s",&again);
  
  if (again=='Y'||again=='y')
  {
  	system("clear");
  	return main();
  }
  else if(again=='n'||again=='N')
  {
  	printf("\n\n--------------------------\n   Thanks for Playing! :D\n--------------------------\n");
  }
  
}

int Mgame()
{

  //init rand seed 
  srand(time(NULL));
  //actual rand num
  randnum = rand() % 100 + 1;
  
	printf("---------------------------------\n\tGUESS THE NUMBER\n---------------------------------\n");
	while (randnum!=inp)
	{
    	
    	printf ("Guess the number (1 to 100): "); scanf ("%s",&inpd);
    	inp = atoi(inpd);
    	if (strcmp(inpd,"secret")==0)
    	{
    		printf("\n%d",randnum);
			inp = randnum;
			return 0;
		}
    	if (inp>100) {
			printf ("--------------------------\nInvalid Input! Enter a numeric character or a value lower than 100.\n--------------------------\n");
  		}
   		 else if (randnum<inp) {
			printf ("--------------------------\nThe secret number is lower\n---------------------------\n");
   		 }
   		   		else if (inp==0) {
			printf ("--------------------------\nInvalid Input! Enter a numeric character or a value higher than 1.\n--------------------------\n");
  		}
		else if (randnum>inp) {
			printf ("--------------------------\nThe secret number is higher\n--------------------------\n");
  		}

	}	
	
  printf ("\n------------------------------\n\tCongratulations!\n------------------------------");

}


int main()
{
	Mgame();
	goback();
	return 0;
}
