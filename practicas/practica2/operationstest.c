#include <stdio.h>
#include "operations.h"

int main()
{
    //test addition.2
    int a = 2147483645;
    int b = 1;
    int result = add(a,b);
    int expected = a + b;

    if( result == expected)
    {
        printf("%s\n", "addition test passed");
    }
    else
    {
        printf("%s\n", "addition test failed");
    }

    //test substraction
    int d = -2147483645;
    int f = 1;
    int resultSubstraction = substraction(d, f);
    int expectedSubstraction = d - f;

    if( resultSubstraction == expectedSubstraction)
    {
        printf("%s\n", "Substraction test passed");
    }
    else
    {
        printf("%s\n", "Substraction test failed");
    }

    return 0;
}