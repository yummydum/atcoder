#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _GLIBCXX_DEBUG
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define debug(x) cout << #x << " = " << x << endl
#define print(x) cout << x << endl;
const ll MOD = 1000000007;
const double PI = 3.14159265358979323846;

int main()
{
    int A, B, H, M;
    cin >> A >> B >> H >> M;

    double theta1 = (H * 60 + M) * 0.5;
    double theta2 = M * 6;
    double kyoukaku = max(theta1, theta2) - min(theta1, theta2);
    if (kyoukaku > 180)
    {
        kyoukaku = 360 - kyoukaku;
    }
    double ans = sqrt(A * A + B * B - 2 * A * B * cos(kyoukaku * PI / 180));

    cout << fixed << setprecision(20);
    cout << ans << endl;
}
