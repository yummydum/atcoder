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

    vector<int> L(N);
    rep(i, N)
    {
        cin >> L[i];
    }

    sort(L.begin(), L.end());

    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int x = max(L[i] - L[j], L[j] - L[i]);
            int y = L[i] + L[j];
            auto upper = lower_bound(L.begin() + j, L.end(), y) - 1; // j+1番目以降で,L[i]+L[j]以上の数の中で最小の要素のインデックスを指すイテレータ - 1 = L[i]+L[j]より小さい数の中で最大の要素のインデックスを指すイテレータ
            auto lower = upper_bound(L.begin() + j, L.end(), x);     // j+1番目以降で, L[i] - L[j]より大きい数の中で最小の要素のインデックスを指すイテレータ
            ans += upper - lower;
        }
    }
    cout << ans << endl;
}
