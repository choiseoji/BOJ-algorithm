#include <iostream>
#include <queue>
using namespace std;

int N, M, K;
int cnt, ans;
char map[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool visited[1001][1001][2][11];  // visited[i][j][0][k] : 밤, visited[i][j][1][k] : 낮

void input(void)
{
    string str;

    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++)
    {
        cin >> str;
        for(int j = 1; j <= M; j++)
        {
            map[i][j] = str[j - 1];
        }
    }
}

void solve(void)
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{1, 1}, K});
    visited[1][1][1][K] = true;

    while (!q.empty())
    {
        cnt++;   // cnt가 홀수이면 낮, cnt가 짝수이면 밤
        int q_size = q.size();
        while (q_size--)
        {
            int x = q.front().first.second;
            int y = q.front().first.first;
            int br = q.front().second;
            q.pop();

            if (x == M && y == N)
            {
                ans = cnt;
                break ;
            }

            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx > 0 && nx <= M && ny > 0 && ny <= N)
                {
                    // 다음 위치가 벽이 아닌 경우 
                    // 1. 이동한다 / 2. 머무른다
                    if (map[ny][nx] == '0')
                    {
                        if (!visited[ny][nx][cnt % 2][br])
                        {
                            q.push({{ny, nx}, br});
                            visited[ny][nx][cnt % 2][br] = true;
                        }
                    }
                    // 다음 위치가 벽인 경우
                    // 1. 낮이면 부순다  / 2.머무른다
                    else
                    {
                        if (cnt % 2 == 1)  // 낮이면
                        {
                            if (br > 0 && !visited[ny][nx][cnt % 2][br])
                            {
                                q.push({{ny, nx}, br - 1});
                                visited[ny][nx][cnt % 2][br] = true;
                            }
                        }
                    }
                    // 머무르는 경우 한꺼번에 처리
                    if (!visited[y][x][cnt % 2][br])
                    {
                        q.push({{y, x}, br});
                        visited[y][x][cnt % 2][br] = true;
                    }
                }
            }
        }
        if (ans > 0)
            break ;
    }
    if (ans == 0)
        ans = -1;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();
    cout << ans;
    return (0);
}