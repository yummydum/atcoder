#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;

    if ((W == 1) || (H == 1))
    {
        cout << 1;
        return 0;
    }

    long ans = 0;
    for (int i = 0; i < H; i++)
    {
        if (i % 2 == 0)
        {
            ans += (W + 1) / 2;
        }
        else
        {
            ans += W / 2;
        }
    }

    cout << ans;
}
