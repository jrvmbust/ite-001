
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//defined some common functionorinos becuz im lz
#define pr printf
#define sf scanf
#define gc getch


main()
{
	char fn[80];
	char mn[80];
	char sn[80];
	char pos[80];
	float hrs;
	float rt;
	float gp;
	int lel;
	int i = 1;
	
	pr("\t\t   ---------------DOGE COMPANY---------------");
	pr("\n\t\t\t     420 Wow St.,Taguig City");
	pr("\n\t\t\t        Tel No. 632-7190");	
	pr("\n\t\t   ==========================================");
	pr("\n\n\t\t\t    =Employees Information=");
	pr("\n\n\n\t\t   Enter first name: ");
	sf("%79[^\n]", fn); //scanf reads everything till a newline comes up. i usually use fgets for strings w/ spaces.
	pr("\n\t\t   Enter middle name: ");
	sf("%s", mn);
	pr("\n\t\t   Enter surname: ");
	sf("%s",sn);
	pr("\n\t\t   Enter Position: ");
	sf("%s",pos);
	pr("\n\t\t   Number of hours worked: ");
	sf("%f",&hrs);
	pr("\n\t\t   Rate per hour: ");
	sf("%f",&rt);
	gp = rt*hrs;
	pr("\n\t\t   ==========================================");
	pr("\n\n\t\t\t     P  A  Y  S  L  I  P");
	pr("\n\n\t\t   Name: %s, %s %.1s.",sn,fn,mn);
	pr("\n\t\t   Rate per hour: %.2f", rt);
	pr("\n\t\t   No. of hours worked: %.2f", hrs);
	pr("\n\t\t   G R O S S  P A Y: %.2f",gp);
	pr("\n\n\t\t   --------------------END-------------------");
	gc();

}
