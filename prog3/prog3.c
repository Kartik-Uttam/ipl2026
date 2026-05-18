#include <stdio.h>

/* Function to print bits of an integer */
void printBits(int n)
{
    int i;

    for(i = 31; i >= 0; i--)
    {
        printf("%d", (n >> i) & 1);
    }

    printf("\n");
}

/* Function to count number of 1 bits */
int countOneBits(int n)
{
    int count = 0;

    while(n)
    {
        count += n & 1;

        n = n >> 1;
    }

    return count;
}

/* Function to check endian */
void checkEndian()
{
    int n = 1;

    char *p = (char*)&n;

    if(*p == 1)
        printf("System is Little Endian\n");
    else
        printf("System is Big Endian\n");
}

/* Function to print float bits */
void printFloatBits(float f)
{
    int *p = (int*)&f;

    int i;

    for(i = 31; i >= 0; i--)
    {
        printf("%d", (*p >> i) & 1);
    }

    printf("\n");
}

int main()
{
    int n;
    float f;

    /* Integer section */
    printf("Enter an integer: ");
    scanf("%d", &n);

    printf("\nBits of integer:\n");
    printBits(n);

    printf("\nNumber of 1 bits = %d\n", countOneBits(n));

    /* Endian section */
    printf("\nEndian Check:\n");
    checkEndian();

    /* Float section */
    printf("\nEnter a floating point number: ");
    scanf("%f", &f);

    printf("\nBits of floating point number:\n");
    printFloatBits(f);

    return 0;
}