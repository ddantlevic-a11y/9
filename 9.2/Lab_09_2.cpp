// Lab_09_2.cpp
// Данилевич Данило
// Лабораторна робота № 9.2
// Директиви препроцесора
// Варіант 7

#include <stdio.h>
#include "macros.h"

#ifndef Z
#define Z 5 // Значення константи Z за замовчуванням
#endif

#ifndef UNIT_TEST
int main()
{
    puts("Lab 9.2. Using macros and preprocessing directives. Variant 7.");

    double x, y, w;
    char ch;

    do {
        printf("Current preprocessor constant Z = %g\n", (double)Z);
        puts("Input variable x:");
        if (scanf("%lf", &x) != 1) break;
        PRINTI(x);

        puts("Input variable y:");
        if (scanf("%lf", &y) != 1) break;
        PRINTI(y);

#if (Z > 3)
        puts("Condition (Z > 3) is true: compiling branch 1");
        puts("Formula: w = max((x - z)^2, x - y)");

        double x_minus_z = x - Z;
        double sqr_xz = SQR(x_minus_z);
        double x_minus_y = x - y;

        w = MAX(sqr_xz, x_minus_y);
        PRINTR(w);
#else
        puts("Condition (Z <= 3) is true: compiling branch 2");
        puts("Formula: w = max(x*y, y*z) + max(z*x, y*z)");

        double xy = x * y;
        double yz = y * Z;
        double zx = Z * x;

        double max1 = MAX(xy, yz);
        double max2 = MAX(zx, yz);

        w = max1 + max2;
        PRINTR(w);
#endif

        puts("Repeat? y/n");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');

    return 0;
}
#endif
