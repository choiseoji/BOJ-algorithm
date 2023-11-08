#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int days, e, n;
int N, L, R;
int board[51][51];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int visited[51][51];
vector<pair<int, int>> v(2600);  // 연합의 크기, 인구 총 합

void init(void)
{
    // visited 배열 초기화
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            visited[i][j] = 0;
        }
    }
    // v 초기화
    v.clear();
}

void input(void)
{
    cin >> N >> L >> R;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }
}

void bfs(int i, int j)
{
    queue<pair<int, int>> q;

    q.push({i, j});
    visited[i][j] = n;
    v[n].first++;
    v[n].second += board[i][j];
    while (!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;
        int cur = board[y][x];
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && visited[ny][nx] == 0)
            {
                int gap;

                gap = abs(cur - board[ny][nx]);
                if (gap >= L && gap <= R)
                {
                    q.push({ny, nx});
                    visited[ny][nx] = n;
                    v[n].first++;
                    v[n].second += board[ny][nx];
                    e = 0;
                }
            }
        }
    }
}

void move(void)
{
    map<int, int> m;

    for(int i = 1; i <= 2600; i++)
    {
        if (v[i].second > 0)
            m.insert({i,v[i].second / v[i].first });
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if (visited[i][j] != 0)
            {
                board[i][j] = m[visited[i][j]];
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    while (1)
    {
        e = 1;
        n = 1;
        init();
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if (!visited[i][j])
                {
                    v[n] = {0, 0};
                    // 인구 이동 가능한지 map에 표시
                    bfs(i, j);
                    n++;
                }
            }
        }
        if (e)
            break;
        // board 보고 인구 이동 시켜주기
        move();
        days++;
    }
    cout << days;
    return (0);
}
