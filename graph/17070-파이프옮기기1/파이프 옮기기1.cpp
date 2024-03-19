#include <iostream>
using namespace std;

int N;
int map[20][20];
int dx[3] = {1, 0, 1};
int dy[3] = {0, 1, 1};

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

bool check_bound(int idx, int y, int x)
{
    if (x >= 1 && x <= N && y >= 1 && y <= N && map[y][x] == 0)
    {
        if (idx == 2)
        {
            int a = y - 1;
            int b = x - 1;
            if (a >= 1 && a <= N && b >= 1 && b <= N 
                && map[a][x] == 0 && map[y][b] == 0)
                return (true);
        }
        else 
            return (true);
    }
    return (false);
}

int dfs(int idx, int y, int x)
{
    int cnt = 0;

    if (y == N && x == N)
        return (1);

    for(int i = 0; i < 3; i++)
    {
        if ((idx == 0 && i == 1) || (idx == 1 && i == 0))
            continue;

        int nx = x + dx[i];
        int ny = y + dy[i];

        if (check_bound(i, ny, nx))
        {
            cnt += dfs(i, ny, nx);
        }
    }
    return (cnt);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    cout << dfs(0, 1, 2);
    return (0);
}
