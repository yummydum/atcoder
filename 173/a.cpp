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
    int x;
    cin >> x;
    int ans = x % 1000;
    if (ans == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << 1000 - (x % 1000) << endl;
    }
}
