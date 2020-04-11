#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, A, B;
    cin >> N >> A >> B;

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        int a = i % 10;
        int b = i / 10 % 10;
        int c = i / 100 % 10;
        int d = i / 1000 % 10;
        int e = i / 10000 % 10;

        int sum = a + b + c + d + e;
        if (A <= sum && sum <= B)
        {
            ans += i;
        }
    }

    cout << ans << endl;
}