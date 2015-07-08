#include <stdio.h>
#include <conio.h>
//defined some common functionorinos becuz im lz
#define pr printf
#define sf scanf
#define gc getch

//asd



main()
{
	int f;//used
	int s;//used
	int d;//used
	int g;//used
	int h;//used
	int k;//used
	int l;//used
	float m;
	float n;
	
	pr("\t\t\tBASIC ARITHMETIC OPERATIONS:\n");
	pr("\n\t\tEnter first number: ");
	sf ("%d",&f);
	pr("\n\t\tEnter second number: ");
	sf("%d", &s);
	d = f+s;
	pr("\n\t\t==========================================");
	pr("\n\t\tThe sum is: %d", d);
	pr("\n\t\t==========================================");
	pr("\n\n\t\tEnter third number: ");
	sf ("%d", &g);
	h = d-g;
	pr("\n\t\t==========================================");
	pr("\n\t\tThe difference is: %d",h);
	pr("\n\t\t==========================================");
	pr("\n\n\t\tEnter fourth number: ");
	sf("%d",&k);
	l = k*h;
	pr("\n\t\t==========================================");
	pr("\n\t\tThe product is: %d", l);
	pr("\n\t\t==========================================");
	pr("\n\n\t\tEnter fifth number: ");
	sf("%f", &m);
	n = l/m;
	pr("\n\t\t==========================================");
	pr("\n\t\tThe quotient is: %.2f", n);
	pr("\n\t\t==========================================");
	gc();
	
}
