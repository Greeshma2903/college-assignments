#include <stdio.h>
#include<stdbool.h>

int stepcount = 0;

struct PW
{
    float p;
    float w;
};

bool search(int L, int H, float pp, float ww, struct PW pair[])
{
    int low = L;
    int high = H;
    stepcount += 2; // for assignments
    while (low <= high)
    {
        stepcount++; // for while loop condition
        int mid = (low + high) / 2;
        stepcount++; // for assignment
        stepcount++; // for if condition
        if (pair[mid].p == pp && pair[mid].w == ww)
        {
            stepcount++; // for return
            return true;
        }
        else if (pair[mid].w < ww)
        {
            stepcount++; // for else if condition
            low = mid + 1;
            stepcount++; // for assignment
        }
        else
        {
            high = mid - 1;
            stepcount++; // for assignment
        }
    }
    stepcount++; // for last while loop condition
    stepcount++; // for return
    return false;
}
void Traceback(float p[], float w[], struct PW pair[], int x[], int m, int n, int b[])
{
    int j;
    int last = b[n + 1] - 1;
    float pp = pair[last].p;
    float ww = pair[last].w;
    int k = n;
    stepcount += 4; // for assignments
    while (pp > 0 && ww > 0)
    {
        stepcount++; // for while loop condition
        bool f = true;
        stepcount++; // for assignment
        for (j = k; j >= 0; j--)
        {
            stepcount++; // for for loop condition
            f = search(b[j], b[j + 1] - 1, pp, ww, pair);
            stepcount++; // for assignment
            stepcount++; // for if conditionif(!f)
            {
                stepcount++; // for if condition
                if (j != n)
                {
                    x[j + 1] = 1;
                    pp = pp - p[j + 1];
                    ww = ww - w[j + 1];
                    stepcount += 3; // for assignments
                }
                else
                {
                    x[j] = 1;
                    pp = pp - p[j];
                    ww = ww - w[j];
                    stepcount += 3; // for assignment
                }
                k = j;
                stepcount++; // for assignment
                stepcount++; // for break
                break;
            }
        }
        stepcount++; // for last for loop condition
    }
    stepcount++; // for last while loop condition
    printf("\nThe resultant vector is :");
    stepcount++; // for cout statement
    for (int i = 1; i <= n; i++)
    {
        stepcount++; // for for loop condition
        printf("%d", x[i]);
        stepcount++; // for cout statements
    }
    stepcount++; // for last for loop condition
    printf("\n");
    stepcount++; // for cout statement
}

int largest(struct PW pair[], float w[], int t, int h, int i, int m)
{
    int low = t;
    int high = h;
    stepcount += 2; // for assignments
    int ans;
    while (low <= high)
    {
        stepcount++; // for while loop condition
        int mid = (low + high) / 2;
        stepcount++; // for assignment
        stepcount++; // for if condition
        if (pair[mid].w + w[i] <= m)
        {
            ans = mid;
            low = mid + 1;
            stepcount += 2; // for assignments
        }
        else
        {
            high = mid - 1;
            stepcount++; // for assignment
        }
    }
    stepcount++; // for last while condition
    stepcount++; // for return
    return ans;
}

void Dknap(float p[], float w[], int x[], int n, int m)
{
    struct PW pair[100];
    int b[n + 1];
    // S0
    b[0] = 1;
    pair[1].p = 0.0;
    pair[1].w = 0.0;
    int t = 1, h = 1; // start and end of s0
    stepcount += 4;   // for assignments
    b[1] = 2;
    int next = 2;
    stepcount += 2; // for assignment
    for (int i = 1; i <= n; i++)
    {
        stepcount++; // for for loop condition
        // generate si
        int k = t;
        int u = largest(pair, w, t, h, i, m);
        stepcount += 2; // for assignments
        for (int j = t; j <= u; j++)
        {
            stepcount++; // for for loop condition
            // generate Si-1 and merge
            int pp = pair[j].p + p[i];
            int ww = pair[j].w + w[i];
            stepcount += 2; // for assignment
            //(pp,ww) is next element in sI-1
            while ((k <= h) && (pair[k].w <= ww))
            {
                stepcount++; // for while loop condition
                pair[next].p = pair[k].p;
                pair[next].w = pair[k].w;
                next++;
                k++;
                stepcount += 4; // for assignment}
                stepcount++;    // for while loop condition
                stepcount++;    // for if condition
                if ((k <= h) && (pair[k].w == ww))
                {
                    stepcount++; // for if condition
                    if (pp < pair[k].p)
                    {
                        pp = pair[k].p;
                        stepcount++; // for assignment
                    }
                    k++;
                    stepcount++; // for assignment
                }
                stepcount++; // for if condition
                if (pp > pair[next - 1].p)
                {
                    pair[next].p = pp;
                    pair[next].w = ww;
                    next++;
                    stepcount += 3; // for assignment
                }
                while ((k <= h) && (pair[next].p <= pair[next - 1].p))
                {
                    stepcount++; // for while loop condition
                    k++;
                    stepcount++; // for assignment
                }
                stepcount++; // for last while loop condition
            }
            stepcount++; // for last for loop condition
            // merge remaining terms
            while (k <= h)
            {
                stepcount++; // for while loop condition
                pair[next].p = pair[k].p;
                pair[next].w = pair[k].w;
                next++;
                k++;
                stepcount += 4; // for assignments
            }
            stepcount++; // for last while loop condition
            // initialise S i+1
            t = h + 1;
            h = next - 1;
            b[i + 1] = next;
            stepcount += 3; // for assignments
        }
        stepcount++; // for last for loop condition
        printf("Subsets: \n");
        stepcount++; // for coutastatementfor(int i=0;i<=n;i++)
        {
            stepcount++; // for for loop condition
            for (int j = b[i]; j <= b[i + 1] - 1; j++)
            {
                stepcount++; // for for loop condition
                printf("( %d, %d)", pair[j].p, pair[j].w);
                stepcount++; // for cout statements
            }
            stepcount++; // for last for loop condition
            printf("\n");
            stepcount++; // for cout statement
        }
        stepcount++; // for last for loop condition
        Traceback(p, w, pair, x, m, n, b);
    }
}

int main()
{
    int n, m;
    printf("Enter no of items : ");
    scanf("%d", &n);
    stepcount += 2; // for cout and cin statements
    float p[n + 1], w[n + 1];
    printf("Enter profits and weight of item : \n");
    stepcount++; // for cout statements
    for (int i = 1; i <= n; i++)
    {
        stepcount++; // for for loop condition
        scanf("%d %d", &p[i], &w[i]);
        stepcount++; // for cin statements
    }
    stepcount++; // for last for loop condition
    printf("Enter capacity of bag : ");
    stepcount++; // for cout statement
    scanf("%d", &m);
    stepcount++; // for cin statement
    int x[n + 1];
    for (int i = 0; i <= n + 1; i++)
    {
        stepcount++; // for for loop condition
        x[i] = 0;
        stepcount++; // for assignment
    }
    stepcount++; // for last for loop condition
    Dknap(p, w, x, n, m);
    float profit = 0, weight = 0;
    for (int i = 1; i <= n; i++)
    {
        stepcount++; // for for loop condition
        profit += (x[i] * p[i]);
        weight += (x[i] * w[i]);
        stepcount += 2; // for assignments
    }
    stepcount++; // for last for loop condition
    printf("Maximum profit : %d", profit);
    printf("Maximum weights occupied : %d", weight);
    stepcount += 2; // for
       // for cout statement
    printf("\nStep counts: %d", stepcount);
    return 0;
}