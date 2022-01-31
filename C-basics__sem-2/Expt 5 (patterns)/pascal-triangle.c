/*
***
Pascal-triangle
      1
     1 1
    1 2 1
   1 3 3 1
  1 4 6 4 1
1 5 10 10 5 1

rows:
*/
#include <stdio.h>
int main()
{
   int n, value = 1, space, i, j;

   printf("Enter the number of rows: ");
   scanf("%d", &n);

   for (i = 0; i < n; i++)
   {
      //spaces
      for (j = 1; j <= (n - i); j++)
         printf(" ");

      // values
      for (j = 0; j <= i; j++)
      {
         if (j == 0 || i == 0)
            value = 1; // first and last terms are 1
         else
            value = value * (i - j + 1) / j;
         printf("%d ", value);
      }
      printf("\n");
   }
   return 0;
}
