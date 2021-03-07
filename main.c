#include "math.trans/math_trans.h"

int main() {
    char *s;
    //если равен -2 - нехватка памяти
    if (getStr(&s) == -2) {
        puts("Memory is out!");
    } else {
        transformation(&s);
        printf("%s\n", s);
        free(s);
    }
    return 0;
}
