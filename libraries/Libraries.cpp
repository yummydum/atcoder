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
}

// vector<vector<要素の型>> 変数名(要素数1, vector<要素の型>(要素数2, 初期値))
int N = 10;
vector<vector<int>> table(N, vector<int>(N, 0));

// double プリントするやつ
// cout << fixed << setprecision(10);
// cout << ans << endl;

// int max_col = *max_element(color.begin(), color.end());

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

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

void shakutori()
{
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
