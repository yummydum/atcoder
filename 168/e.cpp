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
    ll N;
    vector<pair<ll, ll>> I1;
    vector<pair<ll, ll>> I2;
    vector<pair<ll, ll>> I3;
    vector<pair<ll, ll>> I4;
    vector<pair<ll, ll>> Bad;

    cin >> N;
    rep(i, N)
    {
        ll o, k;
        cin >> o >> k;
        pair<ll, ll> p = make_pair(o, k);
        if (o >= 0 && k >= 0)
        {
            I1.push_back(p);
        }
        else if (o >= 0 && k < 0)
        {
            I2.push_back(p);
        }
        else if (o < 0 && k >= 0)
        {
            I3.push_back(p);
        }
        else
        {
            I4.push_back(p);
        }
    }

    sort(I1.begin(), I1.end());
    sort(I2.begin(), I1.end());
    sort(I3.begin(), I1.end());
    sort(I4.begin(), I1.end());

    rep(i, N)
    {
    }
}
