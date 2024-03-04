#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
int x_1, y_1, x_2, y_2;
char map[301][301];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool visited[301][301];

void input(void)
{
    cin >> N >> M;
    cin >> y_1 >> x_1 >> y_2 >> x_2;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            cin >> map[i][j];
        }
    }
}

int solve(void)
{
    int cnt = 0;
    queue<pair<int, int>> q;

    while (1)
    {
        cnt++;
        memset(visited, false, sizeof(visited));
        q.push({y_1, x_1});
        visited[y_1][x_1] = true;
        while (!q.empty())
        {
            int x = q.front().second;
            int y = q.front().first;
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx > 0 && nx <= M && ny > 0 && ny <= N && !visited[ny][nx])
                {
                    if (map[ny][nx] == '#')
                        return (cnt);

                    visited[ny][nx] = true;
                    if (map[ny][nx] == '1')
                        map[ny][nx] = '0';
                    else if (map[ny][nx] == '0')
                        q.push({ny, nx});
                }
            }
        }
    }
    return (-1);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    cout << solve();
    return (0);
}