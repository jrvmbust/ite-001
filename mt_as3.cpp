#include <stdio.h>
#include <conio.h>
#include <ctype.h>

int a,b,c;
char sentence[] = "1st, solve the problem. 2nd, write the code";
main()
{
	printf("Sentence : \"%s\"\n",sentence);
	
	for (a=0;a <43;a++)
	{
		if (isdigit(sentence[a]))
		{
			b++;
		}
		else
		{
			c++;
		}
	}
	printf("\n\nDigits: %d\nLetters: %d",b,c);
}
