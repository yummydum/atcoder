#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _GLIBCXX_DEBUG
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define debug(x) cout << #x << " = " << x << endl
#define print(x) cout << x << endl;

int main()
{
}

// vector<vector<要素の型>> 変数名(要素数1, vector<要素の型>(要素数2, 初期値))

// double プリントするやつ
// cout << fixed << setprecision(10);
// cout << ans << endl;

int sumOfDigits(int n)
{
    int sum = 0;
    while (n > 0)
    { // n が 0 になるまで
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// n個の要素の組み合わせを列挙する
void bitSearch(int n)
{
    for (int bit = 0; bit < (1 << n); ++bit) // 1を左にnbitシフトする; 2^n
    {
        for (int i = 0; i < n; ++i) // n個の要素の上をループ
        {
            if (bit & (1 << i)) // &はbitwiseAND,i個目の要素を選択するか否かのbool
            {
            }
        }
    }
}

struct UnionFind
{
    vector<int> parent; // par[i] \in [1,n] is the parent of ith element
    vector<int> depth;  // depth of the tree whose root is ith element
    vector<int> size;   // size of the tree whose root is the ith element (optional)

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
