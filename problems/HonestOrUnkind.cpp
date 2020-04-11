#include <bits/stdc++.h>
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define _GLIBCXX_DEBUG
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<pair<int, int>>> testimonies;

    // init
    rep(i, N)
    {
        vector<pair<int, int>> vec;
        testimonies.push_back(vec);

        int A;
        cin >> A;
        rep(j, A)
        {
            int x, y;
            cin >> x >> y;
            testimonies[i].push_back(make_pair(x, y));
        }
    }

    // bitwise search
    int ans = 0;
    for (int bit = 0; bit < (1 << N); ++bit)
    {
        bool consistent = true;

        // determine who is honest for this combination
        set<int> honest;
        set<int> liers;

        for (int i = 0; i < N; i++)
        {
            if (bit & (1 << i))
            {
                honest.insert(i);
            }
            else
            {
                liers.insert(i);
            }
        }

        // Check if the testimonies are consistent
        for (int i : honest)
        {
            for (auto t : testimonies[i])
            {
                if (t.second == 0 && !liers.count(t.first - 1))
                {
                    consistent = false;
                }
                else if (t.second == 1 && !honest.count(t.first - 1))
                {
                    consistent = false;
                }
            }
        }

        // Update if larger than maximum
        if (consistent && honest.size() > ans)
        {
            ans = honest.size();
        }
    }

    cout << ans << endl;
}
