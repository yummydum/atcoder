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
    int N;
    cin >> N;
    N = N % 10;
    if (N == 3)
    {
        cout << "bon" << endl;
    }
    else if (N == 0 | N == 1 | N == 6 | N == 8)
    {
        cout << "pon" << endl;
    }
    else
    {
        cout << "hon" << endl;
    }
}
