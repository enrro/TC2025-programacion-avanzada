#include <stdlib.h>
#include <stdio.h>
#include "hash.h"
#include <string.h>
#define HASH_DEBUG "HASH_DEBUG"

printDebug(char *msg)
{
    char hashDebug = getenv(HASH_DEBUG);
    if((hashDebug != NULL && strcmp(hashDebug,"y")) == 0)
    {
        printf("%s\n", msg);
    } 
}

unsigned
doHash(unsigned char *str, unsigned size)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % size;
}

void hashInit(HashInt *hash, int size)
{
    hash->size = size;
    hash->data = (HashElement *)calloc(size, sizeof(HashElement));
    
}

static void hashDoInsert(HashInt *hash, char *key, int value)
{
    char errorMessage[255];
    printDebug("dohash");
    unsigned index = doHash(key, hash->size);
    HashElement *currentElements = &(hash->data[index]);
    sprintf(errorMessage, "index %d", index);
    printDebug(errorMessage);
    if(currentElements->elements == NULL)
    {
        currentElements->elements = (Element *)malloc(2*sizeof(Element));
        currentElements->count = 0;
        currentElements->length = 2;
    }
    if(currentElements->length == currentElements->count)
    {
        currentElements->length *=2;
        currentElements->elements = realloc(currentElements->elements,
                                        currentElements->length * sizeof(Element));
    }
    currentElements->elements[currentElements->count].key = strdup(key);
    currentElements->elements[currentElements->count].value = value;
    currentElements->count += 1;

}

static void hashDoUpsert(HashInt *hash, char *key, int value)
{
    int pos = doHash(key,hash->size);
    int i;
    Element *currentElements = hash->data[pos].elements;
    int currentElementsLength = hash->data[pos].count;

    for(i=0;i<currentElementsLength;i++)
    {
        if(strcmp(key, currentElements[i].key) == 0)
        {
            currentElements[i].value = value;
            break;
        }
    }
}



void hashInsert(HashInt *hash, char *key, int value)
{
    int *oldValue = hashGet(hash, key);
    if(oldValue==NULL)
    {
        hashDoInsert(hash, key, value);
    }
    else
    {
        hashDoUpsert(hash, key, value);
    }
}

int *hashGet(HashInt *hash, char *key)
{
    int pos = doHash(key,hash->size);
    int i;
    Element *currentElements = hash->data[pos].elements;
    int currentElementsLength = hash->data[pos].count;
    int *value = NULL;

    for(i=0;i<currentElementsLength;i++)
    {
        if(strcmp(key, currentElements[i].key) == 0)
        {
            value = malloc(sizeof(int));
            *value = currentElements[i].value;
            break;
        }
    }
    return value;
}