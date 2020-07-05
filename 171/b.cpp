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
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int ans = 0;
    rep(i, K)
    {
        ans += A[i];
    }

    cout << ans << endl;
}
