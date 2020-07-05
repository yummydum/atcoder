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
    vector<int> H(N);
    set<int> ans;

    rep(i, N)
    {
        cin >> H[i];
        ans.insert(i);
    }

    rep(i, M)
    {
        int A, B;

        cin >> A >> B;

        A--;
        B--;

        if (H[A] >= H[B])
        {
            ans.erase(B);
        }
        if (H[B] >= H[A])
        {
            ans.erase(A);
        }
    }

    cout << ans.size() << endl;
}
