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
    // Перевірка обчислення наступного доданку за рекурентним співвідношенням
    // При x = 0.5, a_0 = -0.5, для n = 1: a_1 = a_0 * (-x^2 * 1 / 3) = -0.5 * (-0.25 / 3) = 0.5^3 / 3
    x = 0.5;
    a = -0.5;
    n = 1;
    dod();

    double expected_a = (0.5 * 0.5 * 0.5) / 3.0;
    assert(fabs(a - expected_a) < 1e-7);

    // Для n = 2: a_2 = a_1 * (-x^2 * 3 / 5) = -0.5^5 / 5
    n = 2;
    dod();
    double expected_a2 = -pow(0.5, 5) / 5.0;
    assert(fabs(a - expected_a2) < 1e-7);

    cout << "Test 1 (dod) passed successfully!" << endl;
}

void TestSum()
{
    const double PI = 4.0 * atan(1.0);

    // Тест 1: x = 0.5, eps = 1e-5
    x = 0.5;
    e = 1e-5;
    sum();
    double exact_arcctg = PI / 2.0 - atan(0.5);
    assert(fabs(s - exact_arcctg) < 1e-4);

    // Тест 2: x = 0.0, eps = 1e-5
    x = 0.0;
    e = 1e-5;
    sum();
    exact_arcctg = PI / 2.0 - atan(0.0);
    assert(fabs(s - exact_arcctg) < 1e-6);

    // Тест 3: x = -0.5, eps = 1e-5
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
