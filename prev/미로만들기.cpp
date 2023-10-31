#include <iostream>
#include <queue>
using namespace std;

int n;
char c;
int map[51][51];  // 0: 검은 방, 1: 흰 방
int visited[51][51];  // 색깔 바꾼 방의 개수 카운트
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

void input(void)
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> c;
            map[i][j] = c - '0';
        }
    }
}

void init_visited(void)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            visited[i][j] = 2601;
        }
    }
}

void solve(void)
{
    q.push({0, 0});
    visited[0][0] = 0;

    while (!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                // 흰 방 : 그냥 갈 수 있음
                if (map[ny][nx] == 1)
                {
                    if (visited[ny][nx] > visited[y][x])
                    {
                        visited[ny][nx] = visited[y][x];
                        q.push({ny, nx});
                    }
                }
                // 검은 방: 흰 방으로 색 바꿀 수 있음
                else if (map[ny][nx] == 0)
                {
                    if (visited[ny][nx] > visited[y][x] + 1)
                    {
                        visited[ny][nx] = visited[y][x] + 1;
                        q.push({ny, nx});
                    }
                }
            }
        }
    }
    cout << visited[n - 1][n - 1];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    init_visited();
    solve();
    return (0);
}