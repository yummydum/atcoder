#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

struct UnionFind
{
    vector<int> parent; // par[i] \in [1,n] is the parent of ith element
    vector<int> depth;  // depth of the tree whose root is ith element
    vector<int> size;   // size of the tree whose root is the ith element

    // Constructer
    UnionFind(int n)
    {
        for (int i = 0; i < n; i++)
        {
            parent.push_back(i); // Init root by itself (there is n tree initially)
            depth.push_back(0);
            size.push_back(1);
        }
    };

    // Retrive the parent + contraction for better performance
    int root(int i)
    {
        // Base case
        if (parent[i] == i)
            return i;

        // Contraction by recursion; every node will have the same root by this, and the depth will become 2
        parent[i] = root(parent[i]);

        return parent[i];
    }

    void unite(int x, int y)
    {
        int rx = root(x);
        int ry = root(y);

        // If the trees has the same root, do nothing
        if (rx == ry)
            return;

        // Merge to the shallower tree

        if (depth[rx] < depth[ry])
        {
            parent[rx] = ry;
            size[ry] += size[rx];
        }
        else
        {
            parent[ry] = rx;
            size[rx] += size[ry];

            // If same depth, use x
            if (depth[rx] == depth[ry])
                depth[rx]++;
        }
    }

    // True if x and y belongs to the same tree
    bool same(int x, int y)
    {
        return root(x) == root(y);
    }

    int getSize(int x)
    {
        return size[root(x)];
    }
};

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    UnionFind uf(N);
    vector<int> ans(N);
    vector<vector<int>> frnd(N, vector<int>(0));

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        // Adjust index
        a -= 1;
        b -= 1;

        // Construct union find tree
        uf.unite(a, b);
        frnd[a].push_back(b);
        frnd[b].push_back(a);
    }

    for (int i = 0; i < N; i++)
    {
        ans[i] = uf.getSize(i) - 1;
        ans[i] -= frnd[i].size();
    }

    for (int i = 0; i < K; i++)
    {
        int c, d;
        cin >> c >> d;

        // Adjust index
        c -= 1;
        d -= 1;

        // If in the same group, decrease the count
        if (uf.same(c, d))
        {
            ans[c] -= 1;
            ans[d] -= 1;
        }
    }

    // Main
    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << endl;
    }
}