#include <stdio.h>
#include <stddef.h>

struct Original {
    char a;
    int b;
    double c;
};

struct Reordered {
    double c;
    int b;
    char a;
};

/* Additional example showing how another order increases padding. */
struct ExtraOrder {
    char a;
    double c;
    int b;
};

int main(void)
{
    struct Original x = {'A', 42, 3.14};
    struct Reordered y = {3.14, 42, 'A'};
    struct ExtraOrder z = {'A', 3.14, 42};

    printf("Original: char, int, double\n");
    printf("Size: %zu bytes\n", sizeof(x));
    printf("a: address = %p, offset = %zu\n",
           (void *)&x.a, offsetof(struct Original, a));
    printf("b: address = %p, offset = %zu\n",
           (void *)&x.b, offsetof(struct Original, b));
    printf("c: address = %p, offset = %zu\n",
           (void *)&x.c, offsetof(struct Original, c));

    printf("\nReordered: double, int, char\n");
    printf("Size: %zu bytes\n", sizeof(y));
    printf("c: address = %p, offset = %zu\n",
           (void *)&y.c, offsetof(struct Reordered, c));
    printf("b: address = %p, offset = %zu\n",
           (void *)&y.b, offsetof(struct Reordered, b));
    printf("a: address = %p, offset = %zu\n",
           (void *)&y.a, offsetof(struct Reordered, a));

    printf("\nExtra order: char, double, int\n");
    printf("Size: %zu bytes\n", sizeof(z));
    printf("a: address = %p, offset = %zu\n",
           (void *)&z.a, offsetof(struct ExtraOrder, a));
    printf("c: address = %p, offset = %zu\n",
           (void *)&z.c, offsetof(struct ExtraOrder, c));
    printf("b: address = %p, offset = %zu\n",
           (void *)&z.b, offsetof(struct ExtraOrder, b));

    return 0;
}
