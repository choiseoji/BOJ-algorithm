#include<iostream>
using namespace std;

int t;
int dp[15][15];

void find_dp(void)
{
    // 기저값 : 0 층
    for(int i = 1; i <= 14; i++)
    {
        dp[0][i] = i;
    }
    // dp 계산
    for(int k = 1; k <= 14; k++)
    {
        for(int n = 1; n <= 14; n++)
        {
            if (n == 1)
                dp[k][n] = dp[k - 1][n];
            else
                dp[k][n] = dp[k][n - 1] + dp[k - 1][n];
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    find_dp();
    cin >> t;
    while (t--)
    {
        int k, n;

        cin >> k >> n;
        cout << dp[k][n] << "\n";
    }
    return (0);
}