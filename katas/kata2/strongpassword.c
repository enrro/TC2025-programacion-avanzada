#include <stdio.h>
#include <string.h>
#include <time.h>

#define FEATURES 4

int hasUpperCase(const char *inputString)
{
    int i;
    int len = strlen(inputString);
    for (i = 0; i < len; i++) {
        if (inputString[i] >= 'A' && inputString[i] <= 'Z') {
            return 1;
        }
    }
    return 0;
}

void append(char* s, char c)
{
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

int hasLowerCase(const char *inputString)
{
    int i;
    int len = strlen(inputString);
    for (i = 0; i < len; i++) {
        if (inputString[i] >= 'a' && inputString[i] <= 'z') {
            return 1;
        }
    }
    return 0;
}

int hasDigit(const char *inputString)
{
    int i;
    int len = strlen(inputString);
    for (i = 0; i < len; i++) {
        if (inputString[i] >= '0' && inputString[i] <= '9') {
            return 1;
        }
    }
    return 0;
}

int hasLen(const char *inputString)
{
    int i;
    int len = strlen(inputString);
    if(len>=6 && len<=20){
        return 1;
    }
    return 0;
}


char * strongPasswordChecker(char *password)
{
    int i, lenpass, has_length, has_uppercase, has_lowercase, has_digit;
    has_uppercase = has_lowercase = has_digit = has_length = 0;
    lenpass = strlen(password);

    has_uppercase = hasUpperCase(password);
    has_lowercase = hasLowerCase(password);
    has_length = hasLen(password);
    has_digit = hasDigit(password);



    printf("\n length password: %d has length: %d has uppercase: %d has lowercase: %d has digit: %d",
             lenpass,
             has_length,
             has_uppercase,
             has_lowercase,
             has_digit);
    printf("\n %d", FEATURES-has_length -has_uppercase -has_lowercase -has_digit);

    return password;
}

int main()
{
    char password [] = "alfredo";
    printf("\n%s \n", strongPasswordChecker(password));
    return 0;
}