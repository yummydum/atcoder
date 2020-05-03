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
    int N;
    cin >> N;

    int K;
    vector<vector<int>> tree;
    queue<int> q;
    vector<int> parentCol(N);
    vector<int> deg(N, 1);
    map<pair<int, int>, int> edge;
    vector<pair<int, int>> edge2;

    rep(i, N)
    {
        tree.push_back({});
    }

    rep(i, N - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        deg[a]++;
        tree[a].push_back(b);
        edge2.push_back(make_pair(a, b));
    }

    deg[0]--;

    K = *max_element(deg.begin(), deg.end());

    q.push(0);
    parentCol[0] = -1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        int currentCol = 1;
        for (int child : tree[node])
        {
            q.push(child);
            if (currentCol == parentCol[node])
            {
                currentCol++;
            }
            edge[make_pair(node, child)] = currentCol;
            parentCol[child] = currentCol;
            currentCol++;
        }
    }

    cout << K << endl;
    for (auto p : edge2)
    {
        cout << edge[p] << endl;
    }
}
