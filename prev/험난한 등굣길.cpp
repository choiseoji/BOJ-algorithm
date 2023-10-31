#include <iostream>
#include <queue>
using namespace std;

int N, M, K;
int map[3002][3002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int visited[3002][3002];
queue<pair<int, int>> q;

int range_check(int y, int x)
{
    if (x > 0 && x <= M && y > 0 && y <= N)
        return (1);
    return (0);
}

void make_map(int y, int x, int d)
{
    int up, down;

    up = y;
    down = y;
    for(int i = x - d; i <= x; i++)
    {
        if (range_check(up, i))
            map[up--][i] = 1;
        if (range_check(down, i))
            map[down++][i] = 1;
    }
    up = y - d;
    down = y + d;
    for(int i = x; i <= x + d; i++)
    {
        if (range_check(up, i))
            map[up++][i] = 1;
        if (range_check(down, i))
            map[down--][i] = 1;
    }
}

void input(void)
{
    cin >> N >> M >> K;

    for(int i = 0; i < K; i++)
    {
        int r, c, d;

        cin >> r >> c >> d;
        make_map(r, c, d);  // 교통 정체 테두리만 표시해주기.
    }
}

int solve(void)
{
    q.push({1, 1});
    visited[1][1] = 1;

    while (!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();

        if (x == M && y == N)
        {
            cout << "YES\n" << visited[y][x] - 1;
            return (0);
        }

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx > 0 && nx <= M && ny > 0 && ny <= N)
            {
                if (map[ny][nx] == 0 && !visited[ny][nx])
                {
                    visited[ny][nx] = visited[y][x] + 1;
                    q.push({ny, nx});
                }
            }
        }
    }
    cout << "NO\n";
    return (0);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();
    return (0);
}