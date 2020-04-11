#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> X(N);

    int min = 101;
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> X[i];
        if (X[i] < min)
        {
            min = X[i];
        }
        if (max < X[i])
        {
            max = X[i];
        }
    }

    long ans = LONG_MAX;
    for (int i = min; i <= max; i++)
    {
        long temp = 0;
        for (int x : X)
        {
            temp += (i - x) * (i - x);
        }

        if (temp < ans)
        {
            ans = temp;
        }
    }

    cout << ans << endl;
}
