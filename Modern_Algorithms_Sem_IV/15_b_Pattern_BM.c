#include <stdio.h>
int n, m;

int last(char c, char pattern[])
{
	int i;
	for (i = m - 1; i > 0; i--)
	{
		if (c == pattern[i])
		{
			return i;
		}
	}
	return -1;
}

int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

void BM(char text[], char pattern[])
{
	int i, j = n - 1;
	for (i = m - 1; i <= n - 1;)
	{
		if (pattern[j] == text[i])
		{
			if (j == 0)
			{
				printf("\n=> Pattern match found at index %d\n", i);
				return;
			}
			else
			{
				i--;
				j--;
			}
		}
		else
		{
			i = i + m - min(j, 1 + last(text[i], pattern));
			j = m - 1;
		}
	}
	printf("\n=> Pattern not found\n");
}

int main()
{
	printf("Enter length of text: ");
	scanf("%d", &n);
	printf("Enter length of pattern: ");
	scanf("%d", &m);
	char text[n], pattern[m];

	printf("Enter text: ");
	scanf("%s", &text);
	printf("Enter pattern: ");
	scanf("%s", &pattern);
	BM(text, pattern);
	return 0;
}
