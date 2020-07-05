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
    int A, B, C, K;
    cin >> A >> B >> C >> K;

    if (K < A)
    {
        cout << K << endl;
    }

    else if (K <= A + B)
    {
        cout << A << endl;
    }

    else
    {
        cout << A - (K - A - B) << endl;
    }
}
