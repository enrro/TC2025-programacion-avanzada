#include <stdio.h>
#include "operations.h"

void printTestMessage(int, char *, char *);

int main()
{
    //test addition.2
    int a = 2147483645;
    int b = 1;
    int result = add(a, b);
    int expected = a + b;
    printTestMessage(result == expected,
                     "addition test passed",
                     "addition test failed");

    //test substraction
    int d = -2147483645;
    int f = 1;
    int resultSubstraction = substraction(d, f);
    int expectedSubstraction = d - f;
    printTestMessage(resultSubstraction == expectedSubstraction,
                     "Substraction test passed",
                     "Substraction test failed");


    return 0;
}

void printTestMessage(int testResult,
                      char *passedMessage,
                      char *failedMessage)
{
    if (testResult)
    {
        printf("%s\n", passedMessage);
    }
    else
    {
        printf("%s\n", failedMessage);
    }
}
