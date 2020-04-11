#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> mochi(N);
    for (int i = 0; i < N; i++)
    {
        cin >> mochi.at(i);
    }

    sort(mochi.begin(), mochi.end());

    int ans = 0;
    int prev = -1;
    for (int i = 0; i < N; i++)
    {
        if (mochi.at(i) != prev)
        {
            ans += 1;
        }
        prev = mochi.at(i);
    }

    cout << ans << endl;
}