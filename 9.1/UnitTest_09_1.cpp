// UnitTest_09_1.cpp
// Данилевич Данило
// Модульний тест для Lab_09_1

#include <iostream>
#include <cassert>
#include <cmath>

#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace std;
using namespace nsDod;
using namespace nsSum;
using namespace nsVar;

void TestDod()
{
    x = 0.5;
    a = -0.5;
    n = 1;
    dod();

    double expected_a = (0.5 * 0.5 * 0.5) / 3.0;
    assert(fabs(a - expected_a) < 1e-7);

    n = 2;
    dod();
    double expected_a2 = -pow(0.5, 5) / 5.0;
    assert(fabs(a - expected_a2) < 1e-7);

    cout << "Test 1 (dod) passed successfully!" << endl;
}

void TestSum()
{
    const double PI = 4.0 * atan(1.0);

    x = 0.5;
    e = 1e-5;
    sum();
    double exact_arcctg = PI / 2.0 - atan(0.5);
    assert(fabs(s - exact_arcctg) < 1e-4);

    x = 0.0;
    e = 1e-5;
    sum();
    exact_arcctg = PI / 2.0 - atan(0.0);
    assert(fabs(s - exact_arcctg) < 1e-6);

    x = -0.5;
    e = 1e-5;
    sum();
    exact_arcctg = PI / 2.0 - atan(-0.5);
    assert(fabs(s - exact_arcctg) < 1e-4);

    cout << "Test 2 (sum) passed successfully!" << endl;
}

int main()
{
    TestDod();
    TestSum();

    cout << "\nAll Unit Tests for Lab 9.1 passed successfully!" << endl;
    return 0;
}
