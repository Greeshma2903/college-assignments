/*
Pattern 1:
A B C D E F G F E D C B A
A B C D E F   F E D C B A
A B C D E       E D C B A
A B C D           D C B A
A B C               C B A
A B                   B A
A                       A

rows: 1 to n
columns:
		alpha: 1 to (n-i+1)
		spaces: 3 to (2*i-1)
		alpha: (n-i+1) to 1 __except for first alpha in row 1
*/


#include<stdio.h>

int main()
{
	int i, j, n, k;
	printf("Enter number of rows:");
	scanf("%d", &n);
	
	printf("\nPattern:\n");
	
	for(i=1; i<=n; i++)
	{
		// before space alphabets
		for(j=1; j<=(n-i+1);j++ )
			printf("%c ", 'A'+j - 1);
		
		// spaces
		for(k=3; k<=2*i-1; k++)
			printf("  ");

		
		// after space alphabets
		for(j=(n-i+1); j>=1; j--)
			if(j!=n)	// to not print first-alpha twice
   				printf("%c ", 'A'+j - 1);
	 	
		printf("\n");
	}

	return 0;
}

