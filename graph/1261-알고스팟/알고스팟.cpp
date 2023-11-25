#include <iostream>
#include <queue>
using namespace std;

int N, M;
string str;
char board[101][101];  // 1: 벽
int cnt[101][101];
queue<pair<int, int>> q;  // y, x, 벽 cnt
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void input(void)
{
    cin >> M >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> str;
        for(int j = 0; j < M; j++)
        {
            board[i + 1][j + 1] = str[j];
            cnt[i + 1][j + 1] = 0x3f3f3f3f;
        }
    }
}

void solve(void)
{
    q.push({1, 1});
    cnt[1][1] = 0;
    while (!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx > 0 && nx <= M && ny > 0 && ny <= N)
            {
                if (board[ny][nx] == '0')  // 빈 방인 경우
                {
                    if (cnt[ny][nx] > cnt[y][x])
                    {
                        cnt[ny][nx] = cnt[y][x];
                        q.push({ny, nx});
                    }
                }
                else if (board[ny][nx] == '1')  // 벽인 경우
                {
                    if (cnt[ny][nx] > cnt[y][x] + 1)
                    {
                        cnt[ny][nx] = cnt[y][x] + 1;
                        q.push({ny, nx});
                    }
                }
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();
    cout << cnt[N][M];
    return (0);
}
