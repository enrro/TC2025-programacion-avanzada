#include <stdio.h>
#include <string.h>

char * strongPasswordChecker(char *password){
    int i, lenpass, has_uppercase, has_lowercase, has_digit;
    lenpass = strlen(password);
    has_uppercase, has_lowercase, has_digit = 0;

    if(lenpass>=6 && lenpass<=20){
        printf("%s", "acceptable  \n");
    }
    for(i = 0; i<lenpass;i++){
        password[i] = 'e';
        printf("%c \t", password[i]);
    }

    return password;
}

int main()
{
    char password [] = "alfredo";
    printf("%s \n", password);
    printf("\n%s \n", strongPasswordChecker(password));
    return 0;
}