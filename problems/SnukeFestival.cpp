#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _GLIBCXX_DEBUG
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define debug(x) cout << #x << " = " << x << endl
#define print(x) cout << x << endl;
const ll MOD = 1000000007;

// 二分探索+累積和

int main()
{
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> B(N);
    vector<int> C(N);

    rep(i, N)
    {
        cin >> A[i];
    }

    rep(i, N)
    {
        cin >> B[i];
    }

    rep(i, N)
    {
        cin >> C[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    // i番目の要素が"B[i]より大きいCの要素の数"であるような配列
    vector<int> C_larger(N);
    rep(i, N)
    {
        C_larger[i] = C.size() - (upper_bound(C.begin(), C.end(), B[i]) - C.begin());
    }

    // i番目の要素が,B[i]より大きいCの要素の数 + ... +B[N-1]より大きいCの要素の数 であるような配列
    vector<ll> cumalative_sum(N);
    cumalative_sum[0] = C_larger[N - 1];
    for (int i = 1; i < N; i++)
    {
        cumalative_sum[i] = cumalative_sum[i - 1] + C_larger[N - 1 - i];
    }

    reverse(cumalative_sum.begin(), cumalative_sum.end());

    ll ans = 0;
    rep(i, N)
    {
        // A[i]より大きいBの要素の中で最小の要素のインデックス
        int ind = upper_bound(B.begin(), B.end(), A[i]) - B.begin();
        ans += cumalative_sum[ind];
    }

    cout << ans << endl;
}
