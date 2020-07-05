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
    ll N, K;
    string S;
    cin >> N >> K >> S;

    ll ans = 0;
    if (S[0] == 'R' && S[1] == 'R')
    {
        ans++;
    }
    if (S[S.size() - 1] == 'L' && S[S.size() - 2] == 'L')
    {
        ans++;
    }

    for (ll i = 1; i < S.size() - 1; i++)
    {
        if (S[i] == 'R' && S[i + 1] == 'R')
        {
            ans++;
        }
        else if (S[i] == 'L' && S[i - 1] == 'L')
        {
            ans++;
        }
    }

    ll start = 0;
    while (S[start] == S[0])
    {
        start++;
    }

    bool flag = true;
    char left = S[start];
    for (ll i = start + 1; i < S.size() - 1; i++)
    {
        if (S[i] != left)
        {
            ans += 2;
            K--;
            left = S[i];
            flag = false;
        }

        if (K == 0)
        {
            break;
        }
    }

    if (K > 0)
    {
        if (S[0] == 'L' && S[1] == 'R')
        {
            ans++;
            K--;
        }
    }

    if (K > 0)
    {
        if (S[S.size() - 1] == 'R' && (S[S.size() - 2] == 'L') || flag)
        {
            ans++;
            K--;
        }
    }

    cout << ans << endl;
}
