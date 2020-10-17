#include <stdio.h>
#include "Header.h"
int main()
{
	int i = 0, j = 0, in = 0, glass = 0;
	char A[101];
	char B[5] = {'A','U','E','O','I'};

	printf("Enter the string A \n");
	fgets(A, 101, stdin);

	while (A[i] != 0)
	{
		if (((A[i] >= 'A') && (A[i] <= 'Z')) || ((A[i] >= 'a') && (A[i] <= 'z')))
		{
			if (A[i + 1] == 0) // Условие для последнего слова 
			{
					glass += glas(A[i]);
				if (glass == 0)
						for (j; j <= i; j++)
							printf("%c", A[j]);
			}
			in = 1; // В слове
		}
		else if (in == 1) // Для остальных слов
		{
					glass += glas(A[i-1]);
				if (glass == 0)
				{
					for (j; j < i; j++)
						printf("%c", A[j]);
					printf(" ");
					j = i + 1;
				}
				else
				{
					j = i + 1;
					glass = 0;
				}
				in = 0;
		}
		else
			j = i + 1;
		i++;
	}
	return 0;
}