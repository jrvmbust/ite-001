#include <stdio.h>
#include <conio.h>

/*Vendo Machine Assignment #2 for ITE-001*/
/*Coded by John Rovic Vargas IT11KA3*/
/*VERSION 2 (FOR ASSIGNMENT PASSING)*/

//shoutout dyan kina mike at aaron na tumingin dito sa code ko
//UPDATE - bawal daw while loops. s a d b o i s
//i wrote this code before someone asked kung pwede daw.
//my github has the version that checks if u inputted an alphabet character (atoi) and also checks if the number specified is higher or lower than 1-3 (and goes back to the selection thing. [while loops])
//https://github.com/jrvmbust/ite-001/blob/master/vendo.cpp

const int jpprice = 13; 
const int scprice = 35;
const int cfprice = 17;
int c,d,e,f,g,h,i,j;
int ab;

main()
{
	printf("\n\t\t\t     #BestVendingMachine2015\n");
	printf("\t\t\t----------------------------------\n");
	printf("\t\t\t       What are you buying?\n");
	printf("\t\t\t----------------------------------\n");
	printf("\t\t      (1) NUKE-A-COLA = 35PHP\n");
	printf("\t\t      (2) ZesMoo = 13PHP\n");
	printf("\t\t      (3) KAPE NA HINDI PURO = 17PHP\n");
	printf("\t\t\t----------------------------------\n");
	printf("\t\t\t      Make a selection: "); scanf("%d", &ab); //fgets(ab, sizeof(ab), stdin); this is way better
	switch(ab) 
	{
		case 1:
			printf("\t\t\t----------------------------------\n\t\t\t     You chose NUKE-A-COLA.\n\t\t\t----------------------------------\n");
			printf("\t\t\t      TOTAL COST: %d PHP\n.", scprice);
			printf("\t\t\t    CHANGE FOR HOW MUCH?: "); scanf("%d", &c);
			d = c - scprice;
			e = d / 500;
			f = ((d % 500)/100);
			g = ((d % 100)/50);
			h = ((d % 50)/10);
			i = ((d % 10)/5);
			j = d % 5;
			printf("\t\t\t----------------------------------");
			printf("\n\t\t\t     Your change is %dPHP",d);
			printf("\n\t\t\t----------------------------------");
			printf("\n\t\t\t       Change Breakdown:");
			printf("\n\t\t\t----------------------------------");
			printf("\n\t\t\t%d pc(s) 500PHP \n\t\t\t%d pc(s) 100PHP \n\t\t\t%d pc(s) 50PHP \n\t\t\t%d pc(s) 10PHP \n\t\t\t%d pc(s) 5PHP \n\t\t\t%d pc(s) 1PHP",e,f,g,h,i,j); //onelineyolo
			break;
		case 2:
			printf("\t\t\t----------------------------------\n\t\t\t       You chose ZesMoo.\n\t\t\t----------------------------------\n");
			printf("\t\t\t      TOTAL COST: %d PHP\n", jpprice);
			printf("\t\t\t    CHANGE FOR HOW MUCH?: "); scanf("%d", &c);
			d = c - jpprice;
			e = d / 500;
			f = ((d % 500)/100);
			g = ((d % 100)/50);
			h = ((d % 50)/10);
			i = ((d % 10)/5);
			j = d % 5;
			printf("\t\t\t----------------------------------");
			printf("\n\t\t\t     Your change is %dPHP",d);
			printf("\n\t\t\t----------------------------------");
			printf("\n\t\t\t       Change Breakdown:");
			printf("\n\t\t\t----------------------------------");
			printf("\n\t\t\t%d pc(s) 500PHP \n\t\t\t%d pc(s) 100PHP \n\t\t\t%d pc(s) 50PHP \n\t\t\t%d pc(s) 10PHP \n\t\t\t%d pc(s) 5PHP \n\t\t\t%d pc(s) 1PHP",e,f,g,h,i,j); //onelineyolo
			break;
		case 3:
			printf("\t\t\t----------------------------------\n\t\t\t   You chose KAPE NA HINDI PURO.\n\t\t\t----------------------------------\n");
			printf("\t\t\t       TOTAL COST: %d PHP\n", cfprice);
			printf("\t\t\t    CHANGE FOR HOW MUCH?: "); scanf("%d", &c);
			d = c - cfprice;
			e = d / 500;
			f = ((d % 500)/100);
			g = ((d % 100)/50);
			h = ((d % 50)/10);
			i = ((d % 10)/5);
			j = d % 5;
			printf("\t\t\t----------------------------------");
			printf("\n\t\t\t     Your change is %dPHP",d);
			printf("\n\t\t\t----------------------------------");
			printf("\n\t\t\t       Change Breakdown:");
			printf("\n\t\t\t----------------------------------");
			printf("\n\t\t\t%d pc(s) 500PHP \n\t\t\t%d pc(s) 100PHP \n\t\t\t%d pc(s) 50PHP \n\t\t\t%d pc(s) 10PHP \n\t\t\t%d pc(s) 5PHP \n\t\t\t%d pc(s) 1PHP",e,f,g,h,i,j); //onelineyolo
			break;
		default:
			printf("\t\t\t----------------------------------\n\t\t\t    I n v a l i d Selection.\n\t\t\t----------------------------------\n");
			break;
	}
	printf("\n\t\t\t----------------------------------\n");
	printf("\t\t\t        Please come again.\n");
	printf("\t\t\t----------------------------------\n");
	getch();			
}
