#include <iostream>
using namespace std;

int N;
int map[35][35];
long long dp[35][35][3];

void input(void)
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> map[i][j];
        }
    }
}

bool check_wh(int y, int x)  // 가로, 세로 범위 체크
{
    if (y >= 1 && y <= N && x >= 1 && x <= N && map[y][x] == 0)
        return (true);
    return (false);
}

bool check_diagonal(int y, int x)
{
    if (y >= 1 && y <= N && x >= 1 && x <= N && map[y][x] == 0)
    {
        int dy = y - 1;
        int dx = x - 1;
        if (dy >= 1 && dy <= N && dx >= 1 && dx <= N && map[dy][x] == 0 && map[y][dx] == 0)
            return (true);
    }
    return (false);
}

void solve(void)
{
    dp[1][2][0] = 1;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            // 현재 좌표에서 가로로 가는 경우
            if (check_wh(i, j + 1))
                dp[i][j + 1][0] += (dp[i][j][0] + dp[i][j][2]);

            // 현재 좌표에서 세로로 가는 경우
            if (check_wh(i + 1, j))
                dp[i + 1][j][1] += (dp[i][j][1] + dp[i][j][2]);

            // 현재 좌표에서 대각선으로 가는 경우
            if (check_diagonal(i + 1, j + 1))
                dp[i + 1][j + 1][2] += (dp[i][j][0] + dp[i][j][1] + dp[i][j][2]);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();
    cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
    return (0);
}