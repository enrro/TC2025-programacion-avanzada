#include <stdio.h>
#include <unistd.h>

int main(){
    int pid = fork();
    if(pid == 0){
        pid = fork();
        if(pid == 0){
            printf("Soy el daemon\n");
            while(1){

            }
        }
    }
    return 0;
}