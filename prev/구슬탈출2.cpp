#include <iostream>
#include <queue>
using namespace std;

struct marble_set
{
    pair<int, int> marbles[2];
};

int     N, M;
char    map[13][13];
int     dx[4] = {1, 0, -1, 0};
int     dy[4] = {0, 1, 0, -1};
bool    visited[13][13][13][13];
marble_set  m;
queue<marble_set> q;

void input()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'R')
                m.marbles[0] = {i, j};
            else if (map[i][j] == 'B')
                m.marbles[1] = {i, j};
        }
    }
    q.push(m);
    visited[m.marbles[0].first][m.marbles[0].second][m.marbles[1].first][m.marbles[1].second] = true;
}

void    move(int &cx, int &cy, int &cnt, int dir)
{
    // 벽이나 구멍 만나기 전까지 움직여주기
    while (map[cy][cx] != '#' && map[cy][cx] != 'O')
    {
        cx += dx[dir];
        cy += dy[dir];
        cnt++;
    }
}

void    solve()
{
    int cnt = 0;

    while (!q.empty())
    {
        cnt++;
        int q_size = q.size();
        if (cnt > 10)
            break ;

        while (q_size--)
        {
            marble_set  cur = q.front();
            q.pop();

            // 현재 좌표 
            int rx = cur.marbles[0].second;
            int ry = cur.marbles[0].first;
            int bx = cur.marbles[1].second;
            int by = cur.marbles[1].first;

            // 좌표 움직이기
            for(int i = 0; i < 4; i++)
            {
                int nrx = rx;
                int nry = ry;
                int nbx = bx;
                int nby = by;
                int r_cnt = 0;
                int b_cnt = 0;

                move(nrx, nry, r_cnt, i);
                move(nbx, nby, b_cnt, i);

                // 파란 구슬이 구멍에 빠졌다면 다음으로 넘어가기
                if (map[nby][nbx] == 'O')
                    continue;
                // 빨간 구슬이 구멍에 빠졌다면
                if (map[nry][nrx] == 'O')
                {
                    cout << cnt;
                    return ;
                }
                // 벽을 만난 경우
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
                if (nrx == nbx && nry == nby)
                {
                    // 이동 시간이 짧은게 더 먼저 도착한거임
                    if (r_cnt > b_cnt)
                    {
                        nrx -= dx[i];
                        nry -= dy[i];
                    }
                    else
                    {
                        nbx -= dx[i];
                        nby -= dy[i];
                    }
                }
                // 방문하지 않았다면 큐에 넣어주기
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
    cout << -1;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();
    return (0);
}
