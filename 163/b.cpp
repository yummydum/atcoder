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
    int N, M;
    cin >> N >> M;
    rep(i, M)
    {
        int A;
        cin >> A;
        N -= A;
    }
    if (N < 0)
    {
        cout << -1 << endl;
    }
    else
    {

        cout << N << endl;
    }
}
