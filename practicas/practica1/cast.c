#include <stdio.h>

/*
asterisco es la operacion contenido.
*/
main()
{
    int *p;
    int j = 0, k=0,l=0;
    int a = 250;
    long int d = (long)a * a;
    float f = 4.67;
    int e = 4;
    int c = (int)f + e;

    p=&a;
    *p=400;
    p++;
    *p = 5555;

    //printf("a = %p, d = %ld, f = %f, e = %d, c = %d \n", &a, d, f, e, c);

    printf("a = %d, p = %p, j = %d, k=%d, l= %d", a,p,j,k,l);

    return 0;
}