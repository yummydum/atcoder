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
    map<string, int> M;
    rep(i, N)
    {
        string res;
        cin >> res;
        if (!M.count(res))
        {
            M[res] = 0;
        }
        M[res]++;
    }

    cout << "AC"
         << " x " << M["AC"] << endl;
    cout << "WA"
         << " x " << M["WA"] << endl;
    cout << "TLE"
         << " x " << M["TLE"] << endl;
    cout << "RE"
         << " x " << M["RE"] << endl;
}
