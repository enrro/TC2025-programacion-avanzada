#include <stdio.h>

/*
sizeof(a) / sizeof(typo de dato de a) te entrega el tamaño del arreglo

*/

main()
{
    int a[5] = {1,2,3,4,5};
    int *pa;
    pa = a;
    *pa = 27;
    pa[2] = 45;
    *(pa +3) = 200;

    for(int i=0; i<5;i++){
        printf("a[%d] = %d ", i,a[i]);
    }
    printf("\n");
    
    return 0;

}