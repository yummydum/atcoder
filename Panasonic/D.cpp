#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

char getNextAlphabet(string str)
{
    for (char c : "abcdefghij")
    {
        if (str.find(c) >= 0)
        {
            continue;
        }
        else
        {
            return c;
        }
    }

    // Shoudn't come here
    return 'z';
}

int main()
{
    int N;
    cin >> N;
    if (N == 1)
    {
        cout << "a" << endl;
    }

    set<string> ans = {"a"};
    for (int i = 0; i < N; i++)
    {

        cout << i << endl;
        for (string elem : ans)
        {
            ans.insert("a" + elem);
            ans.insert(elem + getNextAlphabet(elem));
        }
    }

    for (string a : ans)
    {
        cout << a << endl;
    }

    return 0;
}
