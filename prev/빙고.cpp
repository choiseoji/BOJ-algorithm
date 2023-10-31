#include <iostream>
using namespace std;

bool map[5][5];
pair<int, int> loc[26];

void input(void)
{
    int num;

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cin >> num;
            loc[num] = {i, j};
        }
    }
}

int check_is_bingo(void)
{
    int cnt = 0;

    // 가로 확인
    for(int i = 0; i < 5; i++)
    {
        if (map[i][0] && map[i][1] && map[i][2] && map[i][3] && map[i][4])
            cnt++;
    }
    // 세로 확인
    for(int j = 0; j < 5; j++)
    {
        if (map[0][j] && map[1][j] && map[2][j] && map[3][j] && map[4][j])
            cnt++;
    }
    // 대각선 확인
    if (map[0][0] && map[1][1] && map[2][2] && map[3][3] && map[4][4])
        cnt++;
    if (map[0][4] && map[1][3] && map[2][2] && map[3][1] && map[4][0])
        cnt++;
    if (cnt >= 3)
        return (1);
    return (0);
}

void solve(void)
{
    int num;
    int x, y;
    int cnt = 0;
    int ans = 0;

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cin >> num;

            if (ans == 0)
            {
                x = loc[num].second;
                y = loc[num].first;
                map[y][x] = true;
                cnt++;
                if (check_is_bingo())
                {
                    ans = cnt;
                }
            }
        }
    }
    cout << ans;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();
    return (0);
}