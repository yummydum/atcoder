#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N, K;
    cin >> N >> K;

    if (N > K)
    {
        {
            long long amari = N % K;
            long long hamidashi = ((N / K) * K + K) - N;
            if (amari == 0)
            {
                cout << 0 << endl;
            }
            else if (amari < hamidashi)
            {
                cout << amari << endl;
            }
            else
            {
                cout << hamidashi << endl;
            }
        }
    }

    else
    {
        cout << min(K - N, N) << endl;
    }
}