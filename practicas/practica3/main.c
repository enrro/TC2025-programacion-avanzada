#include <stdio.h>
#include <ctype.h>
#include <math.h>

typedef struct a 
{
    long *data;
    int dataSize;
    int position;
} Array;

void appendArray(Array *a, double value)
{
    if (a->data == NULL)
    {
        a-> dataSize = 1;
        a-> position = 0;
        a-> data = (double *)malloc(a->dataSize * sizeof(double));
    }
    if (position == resultSize)
    {
        a->dataSize = 2 * a-> dataSize;
        a->data = (double) realloc(a->data, a->dataSize * sizeof(double));
    }
    a->data[a->position] = value;
    a-> position = a-> position +1;
}



int main()
{
    long Ai;
    int c;
    Array results;
    // long *results = NULL;
    // int resultSize = 1;
    // int position = 0;

    do
    {
        c = getchar();
        while (!isdigit(c))
        {
            c = getchar();
        }
        Ai = 0;
        while (isdigit(c))
        {

            Ai = Ai * 10;
            Ai = Ai + (c - '0');
            c = getchar();
        }

        printf("Ai = %ld\n", Ai);
        // storage the result
        appendArray(&results, sqrt((double)Ai))

    } while (c != 10);
    for (int i = position - 1; i >= 0; i--)
    {
        printf("%.4lf", results[i]);
    }
    return 0;
}