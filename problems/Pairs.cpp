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

    ll N, K, n_m, n_0, n_p, nn_m, nn_0, nn_p;
    cin >> N >> K;

    vector<ll> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    n_m = lower_bound(A.begin(), A.end(), 0) - A.begin();
    n_0 = (upper_bound(A.begin(), A.end(), 0) - A.begin()) - n_m;
    n_p = N - n_m - n_0;
    nn_m = n_m * n_p;
    nn_0 = pow(n_0, 2) + (n_0 * (A.size() - n_0) / 2);
    nn_p = pow(N, 2) - nn_m - nn_0;

    if (K <= n_m)
    {
        bool check_minus(ll x)
        {
            // K番目の数がx(<0)以下かどうか

            // A[i] * A[j] <= x / A[i]
            // A[i+1] * A[j] <= x / A[i+1]
            // abs(A[i]) >= abs(A[i+1])
            // ------0000000++++++++++++
            // i               jjjjjjjjj
            //  i                 jjjjjj
            //   i                   jjj

            // x以下の積が何個あるかを数える
            ll j = n_m + n_0;
            ll count = 0;
            rep(i, n_m)
            {
                while (A[i] * A[j] > x && j < N)
                {
                    j++;
                }
                count += j - n_m - n_0;
            }
            return count >= K;
        }

        ll lb = 0;
        ll ub = pow(*max_element(A.begin(), A.end()), 2);
        while (ub - lb > 1)
        {
            ll mid = (ub + lb) / 2;
            if (check_minus(mid))
            {
                ub = mid;
            }
            else
            {
                lb = mid;
            }
        }

        ans = mid;
    }
    else if (K <= nn_m + nn_0)
    {
        ans = 0;
    }
    else
    {
        bool check_plus(ll x)
        {
            // K番目の数がx(>0)以下かどうか
            // b [++++++++++++++++++++++++]
            //    ijjjjjjjjjjjj
            //     ijjjjjjjj
            //      ijjjjj
            //       ijj
            // b[i] * b[j] <= x
            // b[j] <= x / b[i]
            // b[j] <= x / b[i+1]
            // iが増加するにつれjは減少する必要がある

            // x以下の積が何個あるかを数える
            ll count = nn_m + nn_0;
            for (ll i = n_m + n_0; i < N; i++)
            {
                count += j - i;
            }
            return count;
        }

        ll lb = 0;
        ll ub = pow(*max_element(A.begin(), A.end()), 2);
        while (ub - lb > 1)
        {
            ll mid = (ub + lb) / 2;
            if (check_plus(mid))
            {
                ub = mid;
            }
            else
            {
                lb = mid;
            }
        }

        ans = mid;
    }
}
