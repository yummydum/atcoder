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
    int N, K;
    cin >> N >> K;

    set<int> sunuke;

    rep(i, K)
    {
        int d;
        cin >> d;
        rep(i, d)
        {
            int temp;
            cin >> temp;
            sunuke.insert(temp);
        }
    }

    cout << N - sunuke.size() << endl;
}
