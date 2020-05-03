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
    cin >> N >> K;
    vector<ll> A;

    int neg = 0;
    int zeros = 0;
    int pos = 0;

    rep(i, N)
    {
        ll temp;
        cin >> temp;
        A.push_back(temp);

        if (temp < 0)
        {
            neg++;
        }
        else if (temp == 0)
        {
            zeros++;
        }
        else
        {
            pos++;
        }
    }

    sort(A.begin(), A.end());

    ll negative_pairs = ((neg + pos) * (neg + pos - 1)) / 2;
    ll positive_pairs = (neg * (neg - 1) + pos * (pos - 1));

    if (negative_pairs <= K)
    {
        }
    else if (K < negative_pairs + zeros)
    {
        cout << 0 << endl;
    }
    else
    {
    }
}
