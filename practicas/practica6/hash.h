typedef struct e {
    char *key;
    int value;
} Element;

typedef struct d {
    Element *elements;
    unsigned count;
    unsigned length;
} HashElement;

typedef struct h {
    HashElement *data;
    int size;

} HashInt;

void hashInit(HashInt *, int);
void hashInsert(HashInt *hash, char *, int);
int * hashGet(HashInt *, char *);