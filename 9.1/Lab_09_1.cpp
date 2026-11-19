// Lab_09_1.cpp
// Данилевич Данило
// Лабораторна робота № 9.1
// Простори імен
// Варіант 7

#include <iostream>
#include <cmath>
#include <iomanip>

#include "dod.h"
#include "sum.h"
#include "var.h"
#include "var.cpp"
#include "dod.cpp"
#include "sum.cpp"

using namespace std;
using namespace nsDod;
using namespace nsSum;
using namespace nsVar;

int main()
{
    const double PI = 4.0 * atan(1.0);

    cout << "x_p = "; cin >> x_p;
    cout << "x_k = "; cin >> x_k;
    cout << "dx  = "; cin >> dx;
    cout << "e   = "; cin >> e;
    cout << endl;

    cout << "--------------------------------------------------------" << endl;
    cout << "|" << setw(10) << "x" << " |"
         << setw(14) << "arcctg(x)" << " |"
         << setw(14) << "s" << " |"
         << setw(8)  << "n" << " |" << endl;
    cout << "--------------------------------------------------------" << endl;

    x = x_p;
    while (x <= x_k + dx / 2.0) {
        sum();

        cout << "|" << setw(10) << setprecision(4) << fixed << x << " |"
             << setw(14) << setprecision(6) << fixed << (PI / 2.0 - atan(x)) << " |"
             << setw(14) << setprecision(6) << fixed << s << " |"
             << setw(8)  << n << " |" << endl;

        x += dx;
    }
    cout << "--------------------------------------------------------" << endl;

    cin.get();
    cin.get();
    return 0;
}
