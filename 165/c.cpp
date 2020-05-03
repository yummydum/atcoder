#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _GLIBCXX_DEBUG
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define debug(x) cout << #x << " = " << x << endl
#define print(x) cout << x << endl;
const ll MOD = 1000000007;

struct q
{

    int a, b, c, d;
    q(int _a, int _b, int _c, int _d)
    {
        a = _a;
        b = _b;
        c = _c;
        d = _d;
    }
};

int N, M, Q;
vector<q> r;

int dfs(vector<int> vec)
{
    int size = vec.size();
    int res = 0;

    if (size == N)
    {

        for (q elem : r)
        {
            if (vec[elem.b - 1] - vec[elem.a - 1] == elem.c)
            {
                res += elem.d;
            }
        }

        return res;
    }

    else
    {
        int last;
        if (size == 0)
        {
            last = 1;
        }
        else
        {
            last = vec[size - 1];
        }

        for (int i = last; i <= M; i++)
        {
            vector<int> vec2 = vec;
            vec2.push_back(i);
            int res2 = dfs(vec2);
            if (res2 > res)
            {
                res = res2;
            }
        }

        return res;
    }
}

int main()
{

    cin >> N >> M >> Q;

    rep(i, Q)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        r.push_back(q(a, b, c, d));
    }

    vector<int> vec;
    cout << dfs(vec) << endl;
}
