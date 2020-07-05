#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _GLIBCXX_DEBUG
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define debug(x) cout << #x << " = " << x << endl
#define print(x) cout << x << endl;
const ll MOD = 1000000007;

ll N;
vector<ll> A, B;
vector<ll> C;

ll count(ll M)
{

    if (M == 1)
    {
        C[M - 1] = B[M - 1] - A[M - 1] + 1;
        return 0;
    }

    if (M == N)
    {
        C[M - 1] = B[M - 1] - max(count(M - 1), A[M - 1]) + 1;
    }
    else
    {
        C[M - 1] = min(C[M], B[M - 1]) - max(count(M - 1), A[M - 1]) + 1;
    }
}

int main()
{
    cin >> N;
    rep(i, N)
    {
        ll a, b;
        cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
        C.push_back(0);
    }

    count(N);

    rep(i, N)
    {
        debug(C[i]);
    }

    if (N % 2)
    {
        cout << max(C[(N + 1) / 2], C[(N - 1) / 2]) << endl;
    }
    else
    {
        cout << C[(N + 1) / 2] << endl;
    }
}
