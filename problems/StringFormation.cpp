#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _GLIBCXX_DEBUG
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define debug(x) cout << #x << " = " << x << endl
#define print(x) cout << x << endl;

int main()
{
    string S;
    int Q;

    cin >> S >> Q;

    ll rev_count = 0;

    deque<char> ans;
    for (char c : S)
    {
        ans.push_back(c);
    }

    rep(i, Q)
    {
        int q;
        cin >> q;

        if (q == 1)
        {
            rev_count += 1;
        }
        else
        {
            int F;
            char C;
            cin >> F >> C;

            if (F == 1)
            {
                if (rev_count % 2 == 1)
                {
                    ans.push_back(C);
                }
                else
                {
                    ans.push_front(C);
                }
            }
            else
            {
                if (rev_count % 2 == 1)
                {
                    ans.push_front(C);
                }
                else
                {
                    ans.push_back(C);
                }
            }
        }
    }

    if (rev_count % 2 == 1)
    {
        reverse(ans.begin(), ans.end());
    }

    for (char c : ans)
    {
        cout << c;
    }

    cout << endl;
}
