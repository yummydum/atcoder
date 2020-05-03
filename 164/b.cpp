#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _GLIBCXX_DEBUG
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define debug(x) cout << #x << " = " << x << endl
#define print(x) cout << x << endl;
const ll MOD = 1000000007;

int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    while (A > 0)
    {
        C -= B;

        if (C <= 0)
        {
            cout << "Yes" << endl;
            return 0;
        }

        A -= D;
    }

    cout << "No" << endl;
}
