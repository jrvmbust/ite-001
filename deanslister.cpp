#include <stdio.h>
#include <conio.h>

/*Assignment #1 something for ITE-001*/
/*Coded by John Rovic Vargas IT11KA3*/

//deanslister

int inp;

main()
{
	printf("\n\t\t\tEnter Grade: "); scanf("%i", &inp);
	printf("\n\t       ------------------------------------");
	
	if (inp >=98)
	{
		printf("\n\n\t\t\t  GRADE: 1.00");
	}
	else if (inp < 98, inp >= 95)
	{
		printf("\n\n\t\t\t  GRADE: 1.25");
	}
	else if (inp < 95, inp >=91)
	{
		printf("\n\n\t\t\t  GRADE: 1.50");
	}
	else if (inp <91, inp >=89)
	{
		printf("\n\n\t\t\t  GRADE: 1.75");
	}
	else
	{
		printf("\n\n\t\tSorry, You can\'t be a dean lister ");	
	}
		printf("\n\n\t       ------------------------------------");
	getch();
}

/*switch(inp)
	{
		case 100:
			printf("\n\n\t\t\t  GRADE: 1.00");
		break;
		case 99:
			printf("\n\n\t\t\t  GRADE: 1.00");
		break;
		case 98:
			printf("\n\n\t\t\t  GRADE: 1.00");
		break;
		case 97:
			printf("\n\n\t\t\t  GRADE: 1.25");
		break;
		case 96:
			printf("\n\n\t\t\t  GRADE: 1.25");
		break;
		case 95:
			printf("\n\n\t\t\t  GRADE: 1.25");
		break;
		case 94:
			printf("\n\n\t\t\t  GRADE: 1.50");
		break;
		case 93:
			printf("\n\n\t\t\t  GRADE: 1.50");
		break;
		case 92:
			printf("\n\n\t\t\t  GRADE: 1.50");
		break;
		case 91:
			printf("\n\n\t\t\t  GRADE: 1.75");
		break;
		case 90:
			printf("\n\n\t\t\t  GRADE: 1.75");
		break;
		case 89:
			printf("\n\n\t\t\t  GRADE: 1.75");
		break;
		default:
			printf("\n\n\t\tSorry, You can\'t be a dean lister ");
		break;
	}*/
