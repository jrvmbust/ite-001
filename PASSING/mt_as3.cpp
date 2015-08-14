#include <stdio.h>
#include <conio.h>

int a,b,c;
char sentence[] = "1st, solve the problem. 2nd, write the code";
main()
{
	printf("Sentence : \"%s\"\n",sentence);
	
	for (a=0;a <43;a++)
	{
		if (sentence[a] == '0' ||sentence[a] == '1' ||sentence[a] == '2' ||sentence[a] == '3' ||sentence[a] == '4' ||sentence[a] == '5' ||sentence[a] == '6' ||sentence[a] == '7' ||sentence[a] == '8' ||sentence[a] == '9')
		{
			b++;
		}
		else if (sentence[a] == 'a'||sentence[a] == 'b'||sentence[a] == 'c'||sentence[a] == 'd'||sentence[a] == 'e'||sentence[a] == 'f'||sentence[a] == 'g'||sentence[a] == 'h'||sentence[a] == 'i'||sentence[a] == 'j'||sentence[a] == 'k'||sentence[a] == 'l'||sentence[a] == 'm'||sentence[a] == 'n'||sentence[a] == 'o'||sentence[a] == 'p'||sentence[a] == 'q'||sentence[a] == 'r'||sentence[a] == 's'||sentence[a] == 't'||sentence[a] == 'u'||sentence[a] == 'v'||sentence[a] == 'w'||sentence[a] == 'x'||sentence[a] == 'y'||sentence[a] == 'z')
		{
			c++;
		}
	}
	printf("\n\nDigits: %d\nLetters: %d",b,c);
	getch();
}
