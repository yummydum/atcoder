#include <bits/stdc++.h>
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define _GLIBCXX_DEBUG
using namespace std;

int main()
{
    int N, X, Y;
    cin >> N >> X >> Y;

    for (int k = 1; k < N; k++)
    {
        int ans = 0;
        ans += max(N - k, 0);
        for (int i = 1; i <= X; i++)
        {
            int j = k - (X - i) + Y - 1; // (X - i) + (j - Y) + 1 = k
            if (Y <= j && j <= N)
            {
                ans += 1;
            }
        }
        cout << ans << endl;
    }
}
