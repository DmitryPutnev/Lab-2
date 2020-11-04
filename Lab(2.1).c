#include <stdio.h>

int long_max(char* A) // считает кол-во символов в максимальном слове в строке
{
	int i = 0;
	int max = 0;
	int w = 0;
	int in_word = 0;

	while (A[i] != '\n')
	{
		if (((A[i] >= 'A') && (A[i] <= 'Z')) || ((A[i] >= 'a') && (A[i] <= 'z')))
		{
			w++;
			in_word = 1;
		}
		else if (in_word == 1)
		{
			if (w > max)
				max = w;
			w = 0;
			in_word = 0;
		}
		i++;
	}
	if ((w > max) && (in_word == 1))
		max = w;
	in_word = 0;
	i = 0;
	return max;
}

int long_min(char* A) // считает кол-во символов в минимальном слове в строке
{
	int i = 0;
	int in_word = 0;
	int k = 0;
	int min = 1001;

	while (A[i] != '\n')
	{
		if (((A[i] >= 'A') && (A[i] <= 'Z')) || ((A[i] >= 'a') && (A[i] <= 'z')))
		{
			k++;
			in_word = 1;
		}
		else if (in_word == 1)
		{
			if (k < min)
				min = k;
			k = 0;
			in_word = 0;
		}
		i++;
	}
	if ((k < min) && (in_word == 1))
		min = k;
	in_word = 0;
	i = 0;
	return min;
}

void minimum(char* A) // выводит минимальные слова в строке на экран
{
	int i = 0;
	int j = 0;
	int min = 1001;
	int in_word = 0;
	int k = 0;

	while (A[i] != '\n')
	{
		if (((A[i] >= 'A') && (A[i] <= 'Z')) || ((A[i] >= 'a') && (A[i] <= 'z')))
		{
			k++;
			in_word = 1;
		}
		else if (in_word == 1)
		{
			if (k < min)
				min = k;
			k = 0;
			in_word = 0;
		}
		i++;
	}
	if ((k < min) && (in_word == 1))
		min = k;
	in_word = 0;
	i = 0;
	k = 0;

	while (A[i] != '\n')
	{
		if ((((A[i] >= 'A') && (A[i] <= 'Z')) || ((A[i] >= 'a') && (A[i] <= 'z'))) && (in_word == 0))
		{
			j = i;
			k++;
			in_word = 1;
		}
		else if ((((A[i] >= 'A') && (A[i] <= 'Z')) || ((A[i] >= 'a') && (A[i] <= 'z'))) && (in_word == 1))
		{
			k++;
		}
		else if (in_word == 1)
		{
			if (k == min)
			{
				for (j; j < i; j++)
					printf("%c", A[j]);
				printf(" ");
			}
			k = 0;
			in_word = 0;
		}
		i++;
	}
	if ((k == min) && (in_word == 1))
	{
		for (j; j < i; j++)
			printf("%c", A[j]);
		printf(" ");
	}
}

int main()
{
	int i = 0, j = 0;
	int in_word = 0;
	char A[1001];
	char B[1001] = { 0 };
	char C[1001] = { 0 };
	int k = 0;
	int min = 0;
	int max = 0;
	int g = 0;
	int chet = 1; // счетчик четности и нечетности

	printf("Enter the string A \n");
	fgets(A, 1001, stdin);

	max = long_max(A);
	min = long_min(A);

	int h = max;

	for (h; h >= min + 1; h--)
	{
		while (A[i] != '\n')
		{
			if (((A[i] >= 'A') && (A[i] <= 'Z')) || ((A[i] >= 'a') && (A[i] <= 'z')))
			{
				k++;
				in_word = 1;
			}
			else if (in_word == 1)
			{
				if (k == h)
				{
					chet++;
					if (chet % 2 == 0)
					{
						for (j; j < i; j++)
						{
							B[g] = A[j];
							g++;
							A[j] = ' ';
						}
						B[g] = ' ';
						g++;
					}
				}
				in_word = 0;
				j = i + 1;
				k = 0;
			}
			else
				j = i + 1;
			i++;
		}
		if (in_word == 1)
		{
			if (k == h)
			{
				chet++;
				if (chet % 2 == 0)
				{
					for (j; j < i; j++)
					{
						B[g] = A[j];
						g++;
						A[j] = ' ';
					}
					B[g] = ' ';
					g++;
				}
			}
			in_word = 0;
			k = 0;
		}
		i = 0;
		j = 0;
	}

	g = 0;
	h = min + 1;

	for (h; h <= max; h++)
	{
		while (A[i] != '\n')
		{
			if (((A[i] >= 'A') && (A[i] <= 'Z')) || ((A[i] >= 'a') && (A[i] <= 'z')))
			{
				k++;
				in_word = 1;
			}
			else if (in_word == 1)
			{
				if (k == h)
				{
					for (j; j < i; j++)
					{
						C[g] = A[j];
						g++;
						A[j] = ' ';
					}
					C[g] = ' ';
					g++;
				}
				in_word = 0;
				j = i + 1;
				k = 0;
			}
			else
				j = i + 1;
			i++;
		}
		if (in_word == 1)
		{
			if (k == h)
			{
				for (j; j < i; j++)
				{
					C[g] = A[j];
					g++;
					A[j] = ' ';
				}
				C[g] = ' ';
				g++;
			}
			in_word = 0;
			k = 0;
		}
		i = 0;
		j = 0;
	}
	printf("%s", B);
	minimum(A);
	printf("%s", C);

	return 0;
}