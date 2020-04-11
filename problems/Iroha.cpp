#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, L;
    cin >> N >> L;

    vector<string> strings(N);
    for (int i = 0; i < N; i++)
    {
        cin >> strings.at(i);
    }

    sort(strings.begin(), strings.end());

    string ans = "";
    for (int i = 0; i < N; i++)
    {
        ans += strings.at(i);
    }

    cout << ans << endl;
}
