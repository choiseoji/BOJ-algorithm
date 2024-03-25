#include <iostream>
#include <queue>
using namespace std;

int K, W, H;
int map[201][201];    // 0: 평지, 1: 장애물
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int hdx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int hdy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
bool visited[201][201][31];
queue<pair<pair<int, int>, int>> q;

void input(void)
{
    cin >> K >> W >> H;
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            cin >> map[i][j];
        }
    }
}

void solve(void)
{
    int cnt = 0;

    q.push({{0, 0}, K});
    visited[0][0][K] = true;
    while (!q.empty())
    {
        int q_size = q.size();
        while (q_size--)
        {
            int x = q.front().first.second;
            int y = q.front().first.first;
            int k = q.front().second;
            q.pop();

            if (x == W - 1 && y == H - 1)
            {
                cout << cnt;
                return ;
            }

            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < W && ny >= 0 && ny < H && !visited[ny][nx][k] && map[ny][nx] == 0)
                {
                    q.push({{ny, nx}, k});
                    visited[ny][nx][k] = true;
                }
            }

            if (k > 0)
            {
                for(int i = 0; i < 8; i++)
                {
                    int hnx = x + hdx[i];
                    int hny = y + hdy[i];

                    if (hnx >= 0 && hnx < W && hny >= 0 && hny < H && !visited[hny][hnx][k - 1] && map[hny][hnx] == 0)
                    {
                        q.push({{hny, hnx}, k - 1});
                        visited[hny][hnx][k - 1] = true;
                    }
                }
            }
        }
        cnt++;
    }
    cout << -1;
    return ;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();
    return (0);
}