#include <bits/stdc++.h>
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define _GLIBCXX_DEBUG
using namespace std;

int main()
{
    string s;
    cin >> s;

    bool b1 = s.at(2) == s.at(3);
    bool b2 = s.at(4) == s.at(5);

    if (b1 && b2)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
