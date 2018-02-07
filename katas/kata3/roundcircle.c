#include <stdio.h>

int main()
{
    int x, y, c;
    x = y = 0;
    while((c=getchar()) != EOF)
    {
        switch(c)
        {
            case 'L':
                --x;
                break;
            case 'R':
                ++x;
                break;
            case 'U':
                ++y;
                break;
            case 'D':
                --y;
                break;
            default:
                printf("not an instruction \n");
                break;
        }
    }
    if(x == 0 && y == 0)
    {
        printf("true");
    }
    else
    {
        printf("false");
    }

    printf("x= %d\n y= %d\n", x,y);
    return 0;
}