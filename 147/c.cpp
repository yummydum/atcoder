#include <bits/stdc++.h>
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define _GLIBCXX_DEBUG
using namespace std;

bool isContradiction()
{
}

int main()
{
    int N;
    cin >> N;
    vector<vector<pair<int, int>>> testimony;
    rep(i, N)
    {
        int A;
        cin >> A;
        vector<pair<int, int>> test_i;
        rep(j, A)
        {
            int x, y;
            cin >> x;
            cin >> y;
            pair<int, int> t = make_pair(x, y);
            test_i.push_back(t);
        }
        testimony.push_back(test_i);
    }

    for ()
}
