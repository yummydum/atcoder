#include <bits/stdc++.h>
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define _GLIBCXX_DEBUG
using namespace std;

int main()
{
    int X;
    cin >> X;
    long ans = (X / 500) * 1000 + ((X % 500) / 5) * 5;
    cout << ans << endl;
}
