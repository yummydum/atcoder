#define _GLIBCXX_DEBUG
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> X(N);
    vector<int> costs;

    rep(i, N)
    {
        cin >> X[i];
    }

    rep(i, N - K + 1)
    {
        int left = X[i];
        int right = X[i + K - 1];

        if (left <= 0 && right <= 0)
        {
            costs.push_back(-1 * left);
        }
        else if (left <= 0 && right >= 0)
        {
            costs.push_back(-1 * left + right + min(-1 * left, right));
        }
        else
        {
            costs.push_back(right);
        }
    }

    sort(costs.begin(), costs.end());
    cout << costs.front() << endl;
}
