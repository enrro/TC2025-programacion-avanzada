#include <stdio.h>

int main(){
    int A[] = {12,28,46,32,50};
	int B[] = {50,12,32,46,28};
	int C[5];
    int i, j, length;
    
    
    length = sizeof(A)/sizeof(A[0]);

    for(i=0; i<length; i++){
        //printf("A[%d] = %d \n", i, A[i]);
        for(j=0; j<length; j++){
            if(A[i]==B[j]){
                C[i] = j;
            }
        }
    }

    for(i=0; i<length; i++){
        printf("%d ", C[i]);
    }
    
    //printf("number of elements %d", length);

    return 0;
}

