#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, K;
int map[2001][2001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool visited[2001][2001];
bool visited2[2001][2001];
pair<int, int> start_loc;
queue<pair<int, int>> loc;

void input(void)
{
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 4)
                start_loc = {i, j};
            if (map[i][j] == 3)
                loc.push({i, j});
        }
    }
}

void make_map(void)
{
    int dist = -1;

    while (!loc.empty())
    {
        int q_size = loc.size();
        dist++;
        while (q_size--)
        {
            int x = loc.front().second;
            int y = loc.front().first;
            loc.pop();

            for(int j = 0; j < 4; j++)
            {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited2[ny][nx])
                {
                    if (dist == K)
                        continue;
                    loc.push({ny, nx});
                    visited2[ny][nx] = true;
                    map[ny][nx] = 3;
                }
            }
        }
    }
}

void solve(void)
{
    int dist = 0;

    queue<pair<int, int>> q;
    q.push({start_loc.first, start_loc.second});

    while (!q.empty())
    {
        int q_size = q.size();
        dist++;
        while (q_size--)
        {
            int x = q.front().second;
            int y = q.front().first;
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[ny][nx])
                {
                    if (map[ny][nx] == 0)
                    {
                        q.push({ny, nx});
                        visited[ny][nx] = true;
                    }
                    else if (map[ny][nx] == 2)
                    {
                        cout << dist << "\n";
                        return ;
                    }
                }
            }
        }
    }
    cout << -1;
    return ;
}

int main(void)
{
    input();
    make_map();
    solve();
    return (0);
}