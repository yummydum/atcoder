#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, c) for (int i = 0; i < (int)c; i++)
using namespace std;

int main()
{
    int K;
    cin >> K;
    queue<long long> q;

    // init
    int counter = 0;
    for (int i = 1; i < 10; i++)
    {
        q.push(i);
        counter += 1;
        if (counter == K)
        {
            cout << i << endl;
            return 0;
        }
    }

    // breadth first search
    while (true)
    {
        long long x = q.front();
        q.pop();
        rep(i, 10)
        {
            if (abs(x % 10 - i) <= 1)
            {
                q.push(x * 10 + i);
                counter += 1;
                if (counter == K)
                {
                    cout << x * 10 + i << endl;
                    return 0;
                }
            }
        }
    }
}
