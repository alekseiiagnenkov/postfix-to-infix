#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

struct Elem {
    char arr[100];
    int priority;
    struct Elem *next;
};

void transformation(char **);

int sign(char);

int getStr(char **);

char *getstr();
