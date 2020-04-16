#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _GLIBCXX_DEBUG
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define debug(x) cout << #x << " = " << x << endl
#define print(x) cout << x << endl;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<double> p(N);

    rep(i, N)
    {
        int p_i;
        cin >> p_i;

        // store the sum
        for (int j = 1; j <= p_i; j++)
        {
            p[i] += j;
        }

        p[i] /= p_i;
    }

    double current_sum = 0;
    for (int i = 0; i < K; i++)
    {
        current_sum += p[i];
    }

    double ans = current_sum;
    for (int i = 0; i < N - K; i++)
    {
        current_sum = current_sum - p[i] + p[K + i];
        if (current_sum > ans)
        {
            ans = current_sum;
        }
    }

    cout << fixed << setprecision(10);
    cout << ans << endl;
}