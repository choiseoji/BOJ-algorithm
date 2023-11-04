#include <iostream>
using namespace std;

int ans;
int flag;
int R, C;
char map[10001][501];
int dx[3] = {1, 1, 1};
int dy[3] = {-1, 0, 1};
bool visited[10001][501];

void input(void)
{
    cin >> R >> C;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> map[i][j];
        }
    }
}

void dfs(int y, int x)
{
    if (x == C - 1)
    {
        flag = 1;
        ans++;
        return ;
    }
    for(int i = 0; i < 3; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < C && ny >= 0 && ny < R)
        {
            if (map[ny][nx] == '.' && !visited[ny][nx])
            {
                visited[ny][nx] = true;
                dfs(ny, nx);
                if (flag == 1)
                    return ;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    for(int i = 0; i < R; i++)
    {
        flag = 0;
        dfs(i, 0);
    }
    cout << ans;
    return (0);
}