#include <stdio.h>
#include <stddef.h>

struct Normal {
    char a;
    int b;
    double c;
};

#pragma pack(push)
#pragma pack(1)
struct Packed1 {
    char a;
    int b;
    double c;
};
#pragma pack(pop)

#pragma pack(push)
#pragma pack(2)
struct Packed2 {
    char a;
    int b;
    double c;
};
#pragma pack(pop)

#pragma pack(push)
#pragma pack(4)
struct Packed4 {
    char a;
    int b;
    double c;
};
#pragma pack(pop)

int main(void)
{
    struct Normal normal = {'A', 42, 3.14};
    struct Packed1 p1 = {'A', 42, 3.14};
    struct Packed2 p2 = {'A', 42, 3.14};
    struct Packed4 p4 = {'A', 42, 3.14};

    printf("Without packing\n");
    printf("Size: %zu bytes, alignment: %zu bytes\n",
           sizeof(normal), _Alignof(struct Normal));
    printf("a: address = %p, offset = %zu\n",
           (void *)&normal.a, offsetof(struct Normal, a));
    printf("b: address = %p, offset = %zu\n",
           (void *)&normal.b, offsetof(struct Normal, b));
    printf("c: address = %p, offset = %zu\n",
           (void *)&normal.c, offsetof(struct Normal, c));

    printf("\nWith #pragma pack(1)\n");
    printf("Size: %zu bytes, alignment: %zu bytes\n",
           sizeof(p1), _Alignof(struct Packed1));
    printf("a: address = %p, offset = %zu\n",
           (void *)&p1.a, offsetof(struct Packed1, a));
    printf("b: address = %p, offset = %zu\n",
           (void *)&p1.b, offsetof(struct Packed1, b));
    printf("c: address = %p, offset = %zu\n",
           (void *)&p1.c, offsetof(struct Packed1, c));

    printf("\nWith #pragma pack(2)\n");
    printf("Size: %zu bytes, alignment: %zu bytes\n",
           sizeof(p2), _Alignof(struct Packed2));
    printf("a: address = %p, offset = %zu\n",
           (void *)&p2.a, offsetof(struct Packed2, a));
    printf("b: address = %p, offset = %zu\n",
           (void *)&p2.b, offsetof(struct Packed2, b));
    printf("c: address = %p, offset = %zu\n",
           (void *)&p2.c, offsetof(struct Packed2, c));

    printf("\nWith #pragma pack(4)\n");
    printf("Size: %zu bytes, alignment: %zu bytes\n",
           sizeof(p4), _Alignof(struct Packed4));
    printf("a: address = %p, offset = %zu\n",
           (void *)&p4.a, offsetof(struct Packed4, a));
    printf("b: address = %p, offset = %zu\n",
           (void *)&p4.b, offsetof(struct Packed4, b));
    printf("c: address = %p, offset = %zu\n",
           (void *)&p4.c, offsetof(struct Packed4, c));

    return 0;
}
