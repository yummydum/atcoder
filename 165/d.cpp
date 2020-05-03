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
    ll A, B, N;
    cin >> A >> B >> N;
    ll x = min(N, B - 1);
    cout << (A * x / B) - A * (x / B) << endl;
}
