#include <bits/stdc++.h>
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define _GLIBCXX_DEBUG
using namespace std;

int main()
{
    int N, K;
    cin >> K >> N;
    vector<int> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }

    int longest = 0;
    rep(i, N - 1)
    {

        int diff = A[i + 1] - A[i];
        if (diff > longest)
        {
            longest = diff;
        }
    }

    int diff = K - A[N - 1] + A[0];
    if (diff > longest)
    {
        longest = diff;
    }

    cout << K - longest << endl;
}
