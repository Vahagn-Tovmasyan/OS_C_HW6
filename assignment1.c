#include <stdio.h>

int main(void)
{
    int i = 42;
    char c = 'A';
    double d = 3.14;
    short s = 7;

    printf("int:    size = %zu, alignment = %zu, address = %p\n",
           sizeof(i), _Alignof(int), (void *)&i);

    printf("char:   size = %zu, alignment = %zu, address = %p\n",
           sizeof(c), _Alignof(char), (void *)&c);

    printf("double: size = %zu, alignment = %zu, address = %p\n",
           sizeof(d), _Alignof(double), (void *)&d);

    printf("short:  size = %zu, alignment = %zu, address = %p\n",
           sizeof(s), _Alignof(short), (void *)&s);

    return 0;
}
