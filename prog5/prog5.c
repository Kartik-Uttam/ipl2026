#include <stdio.h>

union Decision
{
    unsigned char flags;

    struct
    {
        unsigned int like_it : 1;
        unsigned int financially_good : 1;
        unsigned int parents_support : 1;
        unsigned int final_decision : 1;

    } d;
};

int main()
{
    union Decision career;

    /* Input values */

    career.d.like_it = 1;

    career.d.financially_good = 1;

    career.d.parents_support = 0;

    /* Decision Logic */

    career.d.final_decision =
    (
        career.d.like_it &&
        career.d.financially_good
    );

    /* Print report */

    printf("Like it           = %u\n", career.d.like_it);

    printf("Financially good  = %u\n", career.d.financially_good);

    printf("Parents support   = %u\n", career.d.parents_support);

    printf("Final decision    = %u\n", career.d.final_decision);

    /* Print flags */

    printf("\nFlags value = %u\n", career.flags);

    return 0;
}