#include <stdio.h>

int main() {
    char *s = "hello";

    printf("String: %s", s);
    printf("Sizeof: %d", sizeof(s));
    printf("String: %s", strlen(s));

    return 0;
}
