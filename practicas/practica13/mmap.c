#include <stdio.h>
#include <fcntl.h>
#include <String.h>
#include <unistd.h>
#include <sys/mman.h>

typedef struct s
{
    char name[20];
    char lastName[20];
    unsigned int id;
    unsigned char cal;
} Student;

int main()
{
    char *fileName = "studentDb.data";
    int fd = open(fileName, 0_RDWR);
    Student *pAvanzada = (Student *)mmap(NULL, 5 * sizeof(Student),
                                         PROT_READ | PROT_WRITE,
                                         MAP_FILE | MAP_PRIVATE,
                                         fd,
                                         0);
    printf("first student %s\n", pAvanzada[0].name);
    strcpy(pAvanzada[1].name, "Pedro");
    munmap(pAvanzada, 5 * sizeof(Student));
}