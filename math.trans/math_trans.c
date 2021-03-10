#include "math_trans.h"

void transformation(char **str) {
    struct Elem *stack = NULL;
    for (int i = 0; i < strlen(*str); i++) {

        int priority = sign((*str)[i]);

        struct Elem *ptr = (struct Elem *) calloc(1, sizeof(struct Elem));
        if (priority == 0) {
            ptr->arr[0] = (*str)[i];
            if (stack != NULL) {
                ptr->next = stack;
            }
            stack = ptr;
            ptr->priority=1;
        } else {
            int flag = 0;
            char arr[100] = {0};
            if (priority <= stack->priority) {
                flag = 1;
                ptr->arr[0] = '(';
            }
            strcat(arr, stack->arr);//замутить для обратной
            //strcat(ptr->arr, stack->arr);//размутить для обратной
            struct Elem *it = stack;
            stack = stack->next;
            free(it);
            strcat(ptr->arr, stack->arr);//перенести с 24 стр на 26 для обратной
            ptr->arr[strlen(ptr->arr)] = (*str)[i];
            strcat(ptr->arr, arr);//замутить для обратной
            it = stack;
            stack = stack->next;
            free(it);
            if (stack != NULL) {
                ptr->next = stack;
            }
            stack = ptr;
            if (flag == 1)
                ptr->arr[strlen(ptr->arr)] = ')';
            ptr->priority = priority;
        }
    }
    free(*str);
    *str = (char *) calloc(strlen(stack->arr)+1, sizeof(char));
    strcat(*str, stack->arr);
    free(stack);
};

int sign(char a) {
    switch (a) {
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        default:
            return 0;
    }
}

char *getstr() {
    char *ptr = (char *) malloc(1);
    char buf[81];
    int n, len = 0;
    *ptr = '\0';
    do {
        n = scanf("%80[^\n]", buf); // n = scanf_s ("%80[^\n]", buf, 81);
        if (n < 0) {

            free(ptr);
            ptr = NULL;
            continue;

        }

        if (n == 0)

            scanf("%*c");

        else {

            len += strlen(buf);
            ptr = (char *) realloc(ptr, len + 1);
            strcat(ptr, buf);

        }
    } while (n > 0);
    return ptr;
}