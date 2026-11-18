#pragma once
#include <stdio.h>

// Макроси математичних операцій
#define SQR(x) ((x) * (x))
#define MAX(y, z) (((y) > (z)) ? (y) : (z))
#define MIN(y, z) (((y) < (z)) ? (y) : (z))
#define ABS(x) (((x) < 0) ? -(x) : (x))

// Макроси виведення результатів
#define PRINTI(w) puts("control output"); printf(#w " = %d\n", (int)(w))
#define PRINTR(w) puts("rezult :"); printf(#w " = %f\n", (float)(w))
