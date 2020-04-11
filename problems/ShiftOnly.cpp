#include <bits/stdc++.h>
using namespace std;

int N, A[200];

int main()
{
    int dmin = 100;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int A;
        cin >> A;
        int d = 0;
        while (A % 2 == 0)
        {
            A /= 2;
            ++d;
        }
        dmin = min(dmin, d);
    }
    cout << dmin << endl;
}
