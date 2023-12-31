#include <iostream>
#include <queue>
using namespace std;

int R, C;
char map[1501][1501];
queue<pair<int, int>> s;
queue<pair<int, int>> ns;
queue<pair<int, int>> w;
queue<pair<int, int>> nw;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool visited[1501][1501];
pair<int, int> start;

void input(void)
{
    cin >> R >> C;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> map[i][j];
            if (map[i][j] != 'X')  // 물과 백조 자리 넣어주기
                w.push({i, j});
            if (map[i][j] == 'L')
                start = {i, j};
        }
    }
}

int swan_bfs(void)
{
    while (!s.empty())
    {
        int x = s.front().second;
        int y = s.front().first;
        s.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < C && ny >= 0 && ny < R && !visited[ny][nx])
            {
                // 백조면 답 출력
                if (map[ny][nx] == 'L')
                    return (1);
                // 물이면 그냥 방문 -> 지금 갈 수 있는 곳은 지금 다 가기
                if (map[ny][nx] == '.')
                {
                    s.push({ny, nx});
                    visited[ny][nx] = true;
                }
                // 빙판이면 ns에 넣어주기 -> 왜냐면 내일이면 녹을 자리이기 때문에 내일 갈 자리를 미리 저장하는 것임
                // 내일 ns 위치부터 탐색을 시작하면 됨
                if (map[ny][nx] == 'X')
                {
                    ns.push({ny, nx});
                    visited[ny][nx] = true;
                }
            }
        }
    }
    return (0);
}

void water_bfs(void)
{
    while (!w.empty())
    {
        int x = w.front().second;
        int y = w.front().first;
        w.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < C && ny >= 0 && ny < R)
            {
                if (map[ny][nx] == 'X')  // 다음 위치가 빙판이면 넣어주기. 하루 지나면 물이 될 것이기 때문
                {
                    nw.push({ny, nx});
                    map[ny][nx] = '.';
                }
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int meet;
    int day = 0;

    input();
    s.push({start.first, start.second});
    visited[start.first][start.second] = true;
    while (1)
    {
        meet = swan_bfs();
        if (meet)
        {
            cout << day;
            return (0);
        }
        water_bfs();
        s = ns;
        w = nw;
        while (!ns.empty())
            ns.pop();
        while (!nw.empty())
            nw.pop();
        day++;
    }
    return (0);
}