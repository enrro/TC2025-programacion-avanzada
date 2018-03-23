#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char *filename = "myfile.txt";
    char *search = argv[1];
    char *replace = argv[2];
    int character;
    int streamPos = 0;
    char isReplaced = 0;
    int i = 0;
    int firstCharacter;
    FILE *myFile = fopen(filename, "r");

    while (1)
    {
        character = fgetc(myFile);
        firstCharacter = character;
        streamPos = ftell(myFile);
        if (feof(myFile))
        {
            break;
        }
        if(character == search[0]){
            i = 0;
            while(!feof(myFile) && search[i] == character){
                character = fgetc(myFile);
                i++;
            }
            if(feof(myFile)){
                break;
            }
            if( i == strlen(search)){
                fputs(replace, stdout);
                isReplaced = 1;
                fseek(myFile, -1, SEEK_CUR);
            }
            else{
                //rewind
                character = firstCharacter;
                fseek(myFile, streamPos, SEEK_SET);
            }
        }
        if(!isReplaced){
            fputc(character, stdout);
        }
        isReplaced = 0;
    }
    fclose(myFile);
    return 0;
}