#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int w, h;
int dirty_place;
int ans, flag;
char map[21][21];  // . : 깨끗한 칸, * : 더러운 칸, x : 가구, o : 로봇 청소기 시작 위치
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pair<int, int>> q;
int visited[21][21];

void init()
{
    memset(visited, 0, sizeof(visited));
    while (!q.empty())
    {
        q.pop();
    }
}

int input(void)
{
    cin >> w >> h;
    if (w == 0 && h == 0)
        return (1);
    dirty_place = 0;
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == '*')
                dirty_place++;
        }
    }
    return (0);
}

int solve(void)
{
    int cnt = 0;
    int q_size;

    while (!q.empty())
    {
        cnt++;
        q_size = q.size();
        while (q_size--)
        {
            int x = q.front().second;
            int y = q.front().first;
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < w && ny >= 0 && ny < h && !visited[ny][nx])
                {
                    if (map[ny][nx] == 'x')
                        continue;
                    if (map[ny][nx] == '*')  // 가장 가까운 더러운 위치
                    {
                        map[ny][nx] = 'o';  // 다시 시작위치로 바꿔주고
                        return (cnt);
                    }
                    q.push({ny, nx});
                    visited[ny][nx] = 1;
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

    while (1)
    {
        if (input())
            break ;
        ans = 0;
        while (dirty_place--)
        {
            flag = 0;
            for(int i = 0; i < h; i++)
            {
                for(int j = 0; j < w; j++)
                {
                    if (map[i][j] == 'o')
                    {
                        init();
                        map[i][j] = '.';
                        q.push({i, j});
                        visited[i][j] = 1;
                        flag = solve();
                        break ;
                    }
                }
                if (flag != 0)
                    break ;
            }
            if (flag == -1)
            {
                ans = -1;
                break;
            }
            ans += flag;
        }
        cout << ans << "\n";
    }
    return (0);
}
