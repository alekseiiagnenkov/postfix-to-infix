#include "math_trans.h"

char *transformation(char **str) {
    struct Elem *stack = NULL;
    for (int i = 0; i < strlen(*str); i++) {
        int priority = sign((*str)[i]);

        if (priority == 0) {
            struct Elem *ptr = (struct Elem *) calloc(1, sizeof(struct Elem));
            ptr->arr[strlen(ptr->arr)] = (*str)[i];
            ptr->priority = 1;
            if (stack != NULL) {
                ptr->next = stack;
            }
            stack = ptr;
        } else {
            struct Elem *ptr = (struct Elem *) calloc(1, sizeof(struct Elem));
/*            int pr = stack->priority;
            int pr1 = sign((*str)[i]);*/
            char arr[100] ={0};
            strcat(arr, stack->arr);
            //if (pr >= pr1)
                ptr->arr[strlen(ptr->arr)] = '(';

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

            //if (pr >= pr1)
                ptr->arr[strlen(ptr->arr)] = ')';

            ptr->priority = priority;
        }
    }
    free(*str);
    *str = (char *) calloc(strlen(stack->arr), sizeof(char));
    strcat(*str, stack->arr);
    free(stack);
    return *str;
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