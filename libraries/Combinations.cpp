#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _GLIBCXX_DEBUG
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define debug(x) cout << #x << " = " << x << endl
#define print(x) cout << x << endl;
const ll MOD = 1000000007;

long comb(long n, long k)
{
    if (n < k || n < 0 || k < 0)
    {
        return 0;
    }
    k = min(k, n - k);
    long ans = 1;
    for (long i = 1; i < k + 1; i++)
    {
        ans *= n - i + 1;
        ans /= i;
    }
    return ans;
}

int main()
{
}
