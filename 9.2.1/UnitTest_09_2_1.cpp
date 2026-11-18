// UnitTest_09_2_1.cpp
// Данилевич Данило
// Модульний тест для Lab_09_2_1

#include <iostream>
#include <cassert>
#include <cmath>

#include "macros.h"

using namespace std;

void TestMacros()
{
    // Тест SQR
    assert(SQR(5) == 25);
    assert(SQR(-4) == 16);
    assert(SQR(2 + 3) == 25); // Перевірка дужок у макросі: (2+3)*(2+3) = 25
    assert(fabs(SQR(2.5) - 6.25) < 1e-7);

    // Тест MAX
    assert(MAX(10, 20) == 20);
    assert(MAX(-5, -15) == -5);
    assert(MAX(3.14, 2.71) == 3.14);

    // Тест MIN
    assert(MIN(10, 20) == 10);
    assert(MIN(-5, -15) == -15);
    assert(MIN(3.14, 2.71) == 2.71);

    // Тест ABS
    assert(ABS(-10) == 10);
    assert(ABS(10) == 10);
    assert(ABS(0) == 0);
    assert(fabs(ABS(-3.5) - 3.5) < 1e-7);

    cout << "Test 1 (Macros SQR, MAX, MIN, ABS) passed successfully!" << endl;
}

void TestBranch1()
{
    // Обчислення гілки при z > 3: w = max((x - z)^2, x - y)
    double x = 1.0;
    double y = 2.0;
    double z = 5.0;

    double x_minus_z = x - z;
    double sqr_xz = SQR(x_minus_z); // (1 - 5)^2 = 16
    double x_minus_y = x - y;       // 1 - 2 = -1
    double w = MAX(sqr_xz, x_minus_y);

    assert(fabs(w - 16.0) < 1e-7);

    // Випадок, коли x - y більше
    x = 10.0;
    y = -10.0; // x - y = 20
    z = 9.0;   // (x - z)^2 = 1
    x_minus_z = x - z;
    sqr_xz = SQR(x_minus_z);
    x_minus_y = x - y;
    w = MAX(sqr_xz, x_minus_y);
    assert(fabs(w - 20.0) < 1e-7);

    cout << "Test 2 (Branch 1: z > 3) passed successfully!" << endl;
}

void TestBranch2()
{
    // Обчислення гілки при z <= 3: w = max(x*y, y*z) + max(z*x, y*z)
    double x = 4.0;
    double y = 2.0;
    double z = 1.0;

    double xy = x * y; // 8
    double yz = y * z; // 2
    double zx = z * x; // 4

    double max1 = MAX(xy, yz); // max(8, 2) = 8
    double max2 = MAX(zx, yz); // max(4, 2) = 4
    double w = max1 + max2;    // 8 + 4 = 12

    assert(fabs(w - 12.0) < 1e-7);

    cout << "Test 3 (Branch 2: z <= 3) passed successfully!" << endl;
}

int main()
{
    TestMacros();
    TestBranch1();
    TestBranch2();

    cout << "\nAll Unit Tests for Lab 9.2.1 passed successfully!" << endl;
    return 0;
}
