#include <stdio.h>
#include <conio.h>

int a,b,c,e;

main()
{
	printf("input length: "); scanf("%d", &a);
	printf("input width: "); scanf("%d", &b);
	printf("\n");
	for(c =0;c<a;c++)
	{
			if (c==a-1||c==0) //prints the first line and the last line with all dots
			{
				for(int d =0;d<b;d++)
				{
					printf("*");	
				}
			printf("\n");
			}
			
			else if (b==1) //prints the dots if width = 1
			{
				for(int d =0;d<b;d++)
				{
					printf("*");	
				}
			printf("\n");
			}
			
			else //ghetto spacing 
			{
				printf("*");
				for(e=0;e<b-2;e++)
				{
					printf(" ");
				}
				printf("*");
				printf("\n");
			}	
	}
	getch();
}
		
		
		

	

