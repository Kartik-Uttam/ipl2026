#include <stdio.h>

struct Bitfield
{
    unsigned int firstbit : 1;
};

int main()
{
    struct Bitfield a;

    a.firstbit = 1;

    printf("firstbit = %u\n", a.firstbit);

    return 0;
}