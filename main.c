#include "math.trans/math_trans.h"

int main() {
    char *a;
    //если равен -2 - нехватка памяти
    if (getStr(&a) == -2) {
        puts("Memory is out!");
    } else {
        transformation(&a);
        printf("%s\n", a);
        free(a);
    }
    return 0;
}
