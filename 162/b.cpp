#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _GLIBCXX_DEBUG
#define rep(i, c) for (int i = 1; i < (int)c; i++)
#define debug(x) cout << #x << " is " << endl

int main()
{
    int N;
    cin >> N;

    ll ans = 0;
    rep(i, N + 1)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            continue;
        }
        else if (i % 3 == 0)
        {
            continue;
        }
        else if (i % 5 == 0)
        {
            continue;
        }
        else
        {
            ans += i;
        }
    }

    cout << ans << endl;
}
