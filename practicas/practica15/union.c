#include <stdio.h>

typedef union i{
    unsigned char part[4];
    unsigned dir;
} IpAddress;

int main(){
    IpAddress myAddress;
    myAddress.part[0] = 127;
    myAddress.part[1] = 0;
    myAddress.part[2] = 0;
    myAddress.part[3] = 1;

    printf("The number is %ud\n", myAddress.dir);
    myAddress.dir += 1;
    printf("The %d %d \n", myAddress.part[0], myAddress.part[3]);
    return 0;
}