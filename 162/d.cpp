#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _GLIBCXX_DEBUG
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define debug(x) cout << #x << " is " << x << endl

int main()
{
    ll N, R = 0, G = 0, B = 0;
    string S;
    cin >> N >> S;

    for (int i = 0; i < S.size(); i++)
    {
        if (S.at(i) == 'R')
        {
            R++;
        }
        else if (S.at(i) == 'G')
        {
            G++;
        }
        else
        {
            B++;
        }
    }

    ll ans = R * G * B;

    rep(i, N)
    {
        for (int j = 1; j < N; j++)
        {

            if (i + 2 * j >= N)
            {
                continue;
            }

            if (S.at(i) != S.at(i + j) && S.at(i + j) != S.at(i + 2 * j) && S.at(i + 2 * j) != S.at(i))
            {
                ans -= 1;
            }
        }
    }

    cout << ans << endl;
}