// Decimal to binary using queue

#include<stdio.h>
#define MAX 50
int decimal_val, binary_val, queue_arr[MAX];
int front = -1, rear = -1;
// insert remainder to queue
void insert(int val){
    if (front == -1)
        front = 0;
    rear = rear + 1;
    queue_arr[rear] = val;
    return;
}
// display queue
void display(int decimal_val)
{
    int i;
    printf("Binary Value of %d: ", decimal_val);
    for(i = rear; i >= front; i--)
    {
        printf("%d", queue_arr[i]);
    }
    printf("\n");
}
// convert to binary
void convert_to_binary()
{
    int cval;
    while (decimal_val > 0)
    {
        cval = decimal_val % 2;
        insert(cval);
        decimal_val /= 2;
    }
}
// MAIN FUNCTION
int main(){
    int i;
    printf("Enter decimal value:");
    scanf("%d",&decimal_val);
    int dec = decimal_val;
    convert_to_binary();
    display(dec);
    return 0;
}
