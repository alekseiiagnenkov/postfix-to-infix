#include "math.trans/math_trans.h"

int main() {
    char *s = getstr();
    transformation(&s);
    printf("%s\n", s);
    free(s);
    return 0;
}
