#include <bits/stdc++.h>
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define _GLIBCXX_DEBUG
using namespace std;

int main()
{

    int N;
    cin >> N;
    map<string, int> counter;

    int max_count = 0;
    rep(i, N)
    {
        string temp;
        cin >> temp;
        if (!counter.count(temp))
        {
            counter[temp] = 0;
        }
        counter[temp] += 1;

        if (counter[temp] > max_count)
        {
            max_count = counter[temp];
        }
    }

    vector<string> ans;
    for (auto p : counter)
    {
        if (p.second == max_count)
        {
            ans.push_back(p.first);
        }
    }

    sort(ans.begin(), ans.end());

    for (string a : ans)
    {
        cout << a << endl;
    }
}
