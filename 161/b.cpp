#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> A(N);

    long total_vote = 0;
    rep(i, N)
    {
        cin >> A[i];
        total_vote += A[i];
    }

    int selected = 0;

    rep(i, N)
    {
        if (A[i] * 4 * M >= total_vote)
        {
            selected += 1;
        }
    }

    if (selected >= M)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
