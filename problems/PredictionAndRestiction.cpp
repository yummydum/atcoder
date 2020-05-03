#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _GLIBCXX_DEBUG
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define debug(x) cout << #x << " = " << x << endl
#define print(x) cout << x << endl;
const ll MOD = 1000000007;

int main()
{
    int N, K, R, S, P;
    cin >> N >> K >> R >> S >> P;
    string T;
    cin >> T;
    string myHand;

    int score = 0;
    rep(i, N)
    {
        if (T[i] == 'r')
        {
            if (i < K)
            {
                myHand.push_back('p');
                score += P;
            }

            else if (i - K >= 0 && myHand[i - K] != 'p')
            {
                myHand.push_back('p');
                score += P;
            }
            else
            {
                myHand.push_back('X');
            }
        }
        else if (T[i] == 'p')
        {

            if (i < K)
            {
                myHand.push_back('s');
                score += S;
            }

            else if (i - K >= 0 && myHand[i - K] != 's')
            {
                myHand.push_back('s');
                score += S;
            }
            else
            {
                myHand.push_back('X');
            }
        }

        else
        {
            if (i < K)
            {
                myHand.push_back('r');
                score += R;
            }

            else if (i - K >= 0 && myHand[i - K] != 'r')
            {
                myHand.push_back('r');
                score += R;
            }
            else
            {
                myHand.push_back('X');
            }
        }
    }

    cout << score << endl;
}
