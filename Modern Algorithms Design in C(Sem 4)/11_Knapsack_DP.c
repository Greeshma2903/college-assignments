#include <stdio.h>
#include <stdlib.h>
#define MAX 130
#define o_max 7
int size;
struct tuple
{
    int tp;
    int tw;
    int obj[o_max];
};

void purge(struct tuple S[MAX])
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (S[i].tp < S[j].tp && S[i].tw > S[j].tw)
            {
                S[i].tp = S[i].tw = -1;
            }
        }
    }
}
void knapsack(int m, int n, int p[n], int w[n])
{
    struct tuple S[MAX];
    S[0].tw = 0, S[0].tp = 0;
    int i, j, k, l;
    for (i = 0; i < n; i++)
        S[0].obj[i] = 0;
    size = 1;
    for (i = 0; i < n; i++)
    {
        for (j = 0, k = size; j < size; j++, k++)
        {
            if (S[j].tw == -1)
            {
                continue;
            }
            S[k].tw = S[j].tw + w[i];
            if (S[k].tw > m)
            {
                S[k].tw = S[k].tp = -1;
                continue;
            }
            S[k].tp = S[j].tp + p[i];
            for (l = 0; l < n; l++)
                S[k].obj[l] = S[j].obj[l];
            S[k].obj[i] += 1;
        }
        size = size * 2;
    }
    purge(S);
    int max_profit = -1, max_weight = -1, index;
    for (i = 0; i < size; i++)
    {
        if (S[i].tw < max_weight)
        {
            continue;
        }
        else if (S[i].tw > max_weight)
        {
            max_weight = S[i].tw, max_profit = S[i].tp;
            index = i;
        }
        else
        {
            if (S[i].tp > max_profit)
            {
                max_profit = S[i].tp, index = i;
            }
        }
    }
    printf("\n\nMax profit: %d\nBag filled: %d\nObjects chosen: (", max_profit, max_weight);
    for (i = 0; i < n; i++)
        printf("x[%d]  ", i + 1);
    printf("): (");
    for (i = 0; i < n; i++)
    {
        if (S[index].obj[i] != 1)
            printf("%d  ", 0);
        else
            printf("%d  ", S[index].obj[i]);
    }
    printf(")");
}

int main()
{
    int n, m, i;
    // Read inputs from user
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter size of knapsack bag: ");
    scanf("%d", &m);
    int p[n], w[n];
    printf("Enter profits : ");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);
    printf("Enter weights : ");
    for (i = 0; i < n; i++)
        scanf("%d", &w[i]);

    // Function call
    knapsack(m, n, p, w);
}