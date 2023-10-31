#include <iostream>
#include <queue>
using namespace std;

char map[10][10];
queue<pair<int, int>> q;
bool visited[10][10];
int dx[9] = {1, 0, -1, 0, 1, 1, -1, -1, 0};
int dy[9] = {0, 1, 0, -1, 1, -1, 1, -1, 0};

void input(void)
{
    for(int i = 1; i <= 8; i++)
    {
        for(int j = 1; j <= 8; j++)
        {
            cin >> map[i][j];
        }
    }
    q.push({8, 1});
    visited[8][1] = true;
}

void move_maze(void)
{
    for(int i = 1; i <= 8; i++)
    {
        map[8][i] = '.';   // 마지막 행 벽들은 다 없애주기
    }
    for(int i = 8; i > 1; i--)   // 벽 밑으로 내려주기
    {
        for(int j = 1; j <= 8; j++)
        {
            if (map[i - 1][j] == '#')
            {
                map[i][j] = '#';
                map[i - 1][j] = '.';
            }
        }
    }
}

void solve(void)
{
    int cnt = 0;
    while (!q.empty())
    {
        int q_size;

        if (cnt != 0)
            move_maze();
        cnt++;
        q_size = q.size();
        while (q_size--)
        {
            int x = q.front().second;
            int y = q.front().first;
            q.pop();

            if (map[y][x] == '#')
            {
                visited[y][x] = false;  // 벽이 캐릭터 있는 칸으로 이동한 경우 visit 배열 초기화
                continue;
            }

            if (x == 8 && y == 1)
            {
                cout << 1;
                exit(0);
            }

            for(int i = 0; i < 9; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (i == 8)  // 제자리에 머문 경우
                {
                    if (nx > 0 && nx <= 8 && ny > 0 && ny <= 8 &&  map[ny][nx] != '#')
                    {
                        q.push({ny, nx});  // 방문 확인 하지 않음.
                    }
                }
                else
                {
                    if (nx > 0 && nx <= 8 && ny > 0 && ny <= 8 && !visited[ny][nx] &&  map[ny][nx] != '#')
                    {
                        q.push({ny, nx});
                        visited[ny][nx] = true;
                    }
                }
            }
        }
    }
    cout << 0;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();
    return (0);
}