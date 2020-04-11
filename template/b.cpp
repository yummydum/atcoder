#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

bool isKaibun(string s)
{
    string temp = s;
    reverse(s.begin(), s.end());
    return temp == s;
}

bool isStrongKaibun(string s)
{
    int N = s.size();
    if (N == 1)
    {
        return true;
    }
    else
    {
        string zenhan = s.substr(0, (N - 1) / 2);
        string kouhan = s.substr((N + 3) / 2 - 1);
        return isKaibun(zenhan) && isKaibun(kouhan);
    }
}

int main()
{
    string S;
    cin >> S;

    if (!isKaibun(S))
    {
        cout << "No" << endl;
        return 0;
    }

    bool ans = isStrongKaibun(S);

    if (ans)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
