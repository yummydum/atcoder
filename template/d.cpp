#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    map<int, int> A;
    long B;
    vector<int> C(N);

    for (int i = 0; i < N; i++)
    {
        cin >> C[i];
    }

    for (int i = 0; i < N; i++)
    {
        if (A.count(C[i]))
        {
            A[C[i]] += 1;
            B += A[C[i]];
        }
        else
        {
            A[C[i]] = 0;
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << B - A[C[i]] << endl;
    }
}