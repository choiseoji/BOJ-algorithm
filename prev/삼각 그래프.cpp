#include <iostream>
using namespace std;

int N;
int map[100001][3];
int dp[100001][3];

void input(void)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> map[i][j];
        }
    }
}

void solve(void)
{
    dp[0][0] = map[0][1];
    dp[0][1] = map[0][1];
    dp[0][2] = map[0][1] + map[0][2];
    for(int i = 1; i < N; i++)
    {
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + map[i][0];
        dp[i][1] = min(min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]), dp[i][0]) + map[i][1];
        dp[i][2] = min(min(dp[i - 1][1], dp[i - 1][2]), dp[i][1]) + map[i][2];
    }
    cout << dp[N - 1][1] << "\n";
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int i;

    i = 1;
    while (1)
    {
        cin >> N;
        if (N == 0)
            break ;
        input();
        cout << i << ". ";
        solve();
        i++;
    }
    return (0);
}
