#include <iostream>
#include <queue>
using namespace std;

struct marble_set
{
    pair<int, int> marbles[2];  // 0: 빨강, 1: 파랑
};

int N, M;
char map[13][13];
marble_set m;
queue<marble_set> q;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool visited[13][13][13][13];  // 빨강, 파랑

void input(void)
{
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'R')
                m.marbles[0] = {i, j};
            if (map[i][j] == 'B')
                m.marbles[1] = {i, j};
        }
    }
    q.push(m);
    visited[m.marbles[0].first][m.marbles[0].second][m.marbles[1].first][m.marbles[1].second] = true;
}

void move(int &x, int &y, int &cnt, int dir)
{
    while (map[y][x] != 'O' && map[y][x] != '#')
    {
        x += dx[dir];
        y += dy[dir];
        cnt++;
    }
}

void solve(void)
{
    int cnt = 0;

    while (!q.empty())
    {
        int q_size = q.size();
        cnt++;
        if (cnt > 10)
            break ;

        while (q_size--)
        {
            // 현재 좌표
            int rx = q.front().marbles[0].second;
            int ry = q.front().marbles[0].first;
            int bx = q.front().marbles[1].second;
            int by = q.front().marbles[1].first;
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                // 다음 좌표
                int nrx = rx;
                int nry = ry;
                int nbx = bx;
                int nby = by;
                int r_cnt = 0;
                int b_cnt = 0;

                // 벽을 만날 때까지 밀어주기
                move(nrx, nry, r_cnt, i);
                move(nbx, nby, b_cnt, i);

                // 파란 구슬이 구멍에 먼저 빠졌다면 continue;
                if (map[nby][nbx] == 'O')
                    continue;
                // 빨간 구슬이 구멍에 먼저 빠졌다면 정답
                if (map[nry][nrx] == 'O')
                {
                    cout << 1;
                    return ;
                }
                // 벽을 만난 경우 한칸 뒤로 가기
                if (map[nry][nrx] == '#')
                {
                    nry -= dy[i];
                    nrx -= dx[i];
                }
                if (map[nby][nbx] == '#')
                {
                    nby -= dy[i];
                    nbx -= dx[i];
                }
                // 구슬 위치가 겹친 경우
                if (nry == nby && nrx == nbx)
                {
                    if (r_cnt < b_cnt)  // 빨강이 그 위치에 먼저 도착함
                    {
                        nbx -= dx[i];
                        nby -= dy[i];
                    }
                    else
                    {
                        nrx -= dx[i];
                        nry -= dy[i];
                    }
                }

                // 구슬의 위치 다 구했으니 방문체크해서 아직 방문하지 않았으면 방문해주기
                if (!visited[nry][nrx][nby][nbx])
                {
                    visited[nry][nrx][nby][nbx] = true;

                    m.marbles[0] = {nry, nrx};
                    m.marbles[1] = {nby, nbx};
                    q.push(m);
                }
            }
        }
    }
    cout << 0;
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