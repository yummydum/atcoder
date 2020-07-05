#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _GLIBCXX_DEBUG
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define debug(x) cout << #x << " = " << x << endl
#define print(x) cout << x << endl;
const ll MOD = 1000000007;
double eps = pow(10, -6);

int main()
{
    int X;
    cin >> X;
    for (ll A = -1000; A < 1000; A++)
    {
        ll B5 = pow(A, 5) - X;
        double B = pow(B5, 1.0 / 5.0);

        if ((B - floor(B)) < eps)
        {
            cout << A << " " << floor(B) << endl;
            return 0;
        }
    }
}