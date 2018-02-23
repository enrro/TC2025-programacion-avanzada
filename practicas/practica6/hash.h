typedef struct e {
    char *key;
    int value;
} Element;

typedef struct d {
    Element *elements;
    int count;
    int size;
} HashElement;

typedef struct h {
    HashElement *data;
    int size;

} HashInt;

void hashInit(HashInt *, int);
void hashInsert(HashInt *hash, char *, int);