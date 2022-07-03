#include <stdio.h>
int n, m;

void BruteForce(char text[], char pattern[])
{
	int i, j;
	for (i = 0; i < n - m; i++)
	{	
		for (j = 0; j < m && text[i + j] == pattern[j];)
		{
			j++;
		}
		if (j == m)
		{
			printf("Pattern match found at index %d\n", i);
			return;
		}
	}
	printf("Pattern not found\n");
}

int main()
{
	printf("Enter length of text: ");
	scanf("%d", &n);
	printf("Enter length of pattern: ");
	scanf("%d", &m);

	// Read Text and Pattern 
	char text[n], pattern[m];
	printf("Enter text: ");
	scanf("%s", &text);
	printf("Enter pattern: ");
	scanf("%s", &pattern);

	// Call algo
	BruteForce(text, pattern);

	return 0;
}
