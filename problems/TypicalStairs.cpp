#include <bits/stdc++.h>
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define _GLIBCXX_DEBUG
using namespace std;

int main()
{
    // input
    int N, M;
    cin >> N >> M;
    set<int> broken;
    rep(i, M)
    {
        int a;
        cin >> a;
        broken.insert(a - 1);
    }

    // memoize search
    vector<long long> memo;
    rep(i, N)
    {
        long comb;

        if (broken.count(i))
        {
            comb = 0;
        }
        else if (i == 0)
        {
            comb = 1;
        }
        else if (i == 1)
        {
            comb = 1 + memo[i - 1];
        }
        else
        {
            comb = (memo[i - 1] + memo[i - 2]) % 1000000007;
        }

        memo.push_back(comb);

        // cout << "i: " << i << " Comb: " << memo[i] << endl;
    }

    cout << memo[N - 1] << endl;
}