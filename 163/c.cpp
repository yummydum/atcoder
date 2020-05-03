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

    map<int, int> A;
    for (int i = 0; i < N - 1; i++)
    {
        int temp;
        cin >> temp;
        if (!A.count(temp - 1))
        {
            A[temp - 1] = 0;
        }
        A[temp - 1]++;
    }

    rep(i, N)
    {

        if (!A.count(i))
        {
            cout << 0 << endl;
        }
        else
        {
            cout << A[i] << endl;
        }
    }
}