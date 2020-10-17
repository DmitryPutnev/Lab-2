#include <stdio.h>
int glas(char a)
{
	if ((a == 'A') || (a == 'a') || (a == 'U') || (a == 'u') || (a == 'E')
		|| (a == 'e') || (a == 'O') || (a == 'o') || (a == 'I') || (a == 'i'))
		return 1;
	else
		return 0;
}