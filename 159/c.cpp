#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main()
{
    double L;
    cin >> L;
    double a = L / 3;
    double b = L / 3;
    double c = L - a - b;
    cout << fixed << setprecision(10);
    cout << a * b * c << endl;
}
