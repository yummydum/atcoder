#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _GLIBCXX_DEBUG
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define debug(x) cout << #x << " is " << endl

int main()
{
    string N;
    cin >> N;
    if (N.at(0) == '7' || N.at(1) == '7' || N.at(2) == '7')
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
