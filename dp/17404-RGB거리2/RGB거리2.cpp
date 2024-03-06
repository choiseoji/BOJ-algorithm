#include <iostream>
#include <algorithm>
using namespace std;

int N, ans;
int rgb[1002][3];
int dp[1002][3];

void input(void)
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> rgb[i][j];
        }
    }
}

void solve(void)
{
    // 1번 집이 red
    dp[0][0] = rgb[0][0];
    dp[0][1] = dp[0][2] = 0x3f3f3f3f;
    for(int i = 1; i < N; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rgb[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rgb[i][2];
    }
    ans = min(dp[N - 1][1], dp[N - 1][2]);

    // 2번 집이 green
    dp[0][1] = rgb[0][1];
    dp[0][0] = dp[0][2] = 0x3f3f3f3f;
    for(int i = 1; i < N; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rgb[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rgb[i][2];
    }
    ans = min(ans, min(dp[N - 1][0], dp[N - 1][2]));

    // 3번 집이 blue
    dp[0][2] = rgb[0][2];
    dp[0][0] = dp[0][1] = 0x3f3f3f3f;
    for(int i = 1; i < N; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rgb[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rgb[i][2];
    }
    ans = min(ans, min(dp[N - 1][0], dp[N - 1][1]));
}

int main(void)
{
    input();
    solve();
    cout << ans;
    return (0);
}