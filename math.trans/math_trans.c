#include "math_trans.h"

void transformation(char **str) {
    struct Elem *stack = NULL;
    for (int i = 0; i < strlen(*str); i++) {
        int priority = sign((*str)[i]);

        if (priority == 0) {
            struct Elem *ptr = (struct Elem *) calloc(1, sizeof(struct Elem));
            ptr->arr[strlen(ptr->arr)] = (*str)[i];
            //ptr->priority = 1;
            if (stack != NULL) {
                ptr->next = stack;
            }
            stack = ptr;
        } else {
            struct Elem *ptr = (struct Elem *) calloc(1, sizeof(struct Elem));
            char arr[100] = {0};
            ptr->arr[strlen(ptr->arr)] = '(';
            strcat(arr, stack->arr);
            struct Elem *it = stack;
            stack = stack->next;
            free(it);
            strcat(ptr->arr, stack->arr);
            ptr->arr[strlen(ptr->arr)] = (*str)[i];
            strcat(ptr->arr, arr);
            it = stack;
            stack = stack->next;
            free(it);
            if (stack != NULL) {
                ptr->next = stack;
            }
            stack = ptr;
            ptr->arr[strlen(ptr->arr)] = ')';
            ptr->priority = priority;
        }
    }
    free(*str);
    *str = (char *) calloc(strlen(stack->arr), sizeof(char));
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

//Ввод
int getStr(char **s) //получаем строку из входного потока
{
    char buf[81];
    int n;           //сюда будет записываться результат scanf
    int len = 0;     //сюда длина результирующей строки
    *s = (char *) malloc(1);//указатель на результирующую сткроу
    **s = '\0';//ноль байт, пока строка имеет только конец строки
    do {
        n = scanf("%80[^\n]", buf);//считываем буфер
        if (n > 0) {           //если буфер не пустой
            len += strlen(buf);//увеличиваем результирующую длину
            *s = (char *) realloc(*s, len + 1);//добавляем память
            if (*s)            //если память выделилась
                strcat(*s, buf);//копируем строку из буфера в конец нашей строки
            else {            //если память не выделилась
                free(*s);//очищаем память
                return -2;
            }
        } else
            scanf("%*c");//если перенос строки, то очищаем входной поток
    } while (n > 0);       //пока во входном потоке есть хоть один символ
    return 0;
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