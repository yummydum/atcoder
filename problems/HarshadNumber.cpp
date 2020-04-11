#include <bits/stdc++.h>
using namespace std;


int main()
{
    int ans = 0;
    int A;
    int B;
    cin >> A;
    cin >> B;
    for (int i = A; i <= B; i++)
    {
        int inverse = 0;
        for (int j = 1; j <= 10000; j *= 10)
        {
            inverse += (10000 / j) * ((i / j) % 10);
        }
        if (i == inverse)
        {
            ans += 1;
        }
    }

    cout << ans << endl;
}
