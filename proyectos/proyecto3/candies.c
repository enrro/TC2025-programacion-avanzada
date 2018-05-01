#include <stdio.h>
#include <stdlib.h>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

int gcd(int, int);

int main(){
    int iterations, a, b, c,d, g, r1, r2, result, i;
    scanf("%d", &iterations);
    for(i=0; i<iterations;i++){
        scanf("%d %d %d %d", &a, &b, &c, &d);
        g = gcd(c,d);
        r1 = abs(a - b) % g;
        r2 = abs(b - a) % g;
        printf("%d\n",MIN(r1,r2));
    }
    return 0;
}

int gcd(int a, int b){
    if(a == 0){
        return b;
    }
    return gcd(b%a,a);
}