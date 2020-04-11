#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int W, N, K;
    cin >> W >> N >> K;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++)
        cin >> A[i] >> B[i];
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(W + 1, vector<int>(K + 1)));
    // dp[i][j][k]: i番目までで，残りの幅がj,残りの個数がkの時の最大値を求める
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            for (int k = 0; k <= K; k++)
            {
                // 入らないケースは一個前と同じ
                if (A[i - 1] > j || k == 0)
                {
                    dp[i][j][k] = dp[i - 1][j][k];
                }
                // 入るケースは入れる場合と入れない場合でmaxを取る
                else
                {
                    dp[i][j][k] = max(dp[i - 1][j - A[i - 1]][k - 1] + B[i - 1], dp[i - 1][j][k]);
                }
                if (i == 1 && j == 5 && k == 1)
                {
                    // cout << "i:" << i << "j:" << j << "k:" << k << "dp:" << dp[i][j][k] << endl;
                }
            }
        }
    }

    cout << dp.at(N).at(W).at(K) << endl;
}