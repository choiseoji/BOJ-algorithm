#include <iostream>
#include <queue>
using namespace std;

struct coin_set {
    pair<int, int> coins[2];
};

int N, M;
char map[21][21];
coin_set coin;
queue<coin_set> q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int visited[21][21][21][21];

void input(void)
{
    int k = 0;

    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'o')
            {
                coin.coins[k++] = {i, j};
            }
        }
    }
    q.push(coin);
    visited[coin.coins[0].first][coin.coins[0].second][coin.coins[1].first][coin.coins[1].second] = 1;
}

int in_range(int y, int x)
{
    if (y >= 0 && y < N && x >= 0 && x < M)
        return (1);
    return (0);
}

int solve()
{
    int q_size;
    int cnt = 0;

    while (!q.empty())
    {
        cnt++;

        if (cnt > 10)
            return (-1);
        
        q_size = q.size();
        for(int i = 0; i < q_size; i++)
        {
            coin_set cur = q.front();
            q.pop();

            int x1 = cur.coins[0].second;
            int y1 = cur.coins[0].first;
            int x2 = cur.coins[1].second;
            int y2 = cur.coins[1].first;

            for(int i = 0; i < 4; i++)
            {
                int nx1 = x1 + dx[i];
                int ny1 = y1 + dy[i];
                int nx2 = x2 + dx[i];
                int ny2 = y2 + dy[i];

                int check1 = in_range(ny1, nx1);
                int check2 = in_range(ny2, nx2);

                if (check1 + check2 == 0)  //  두 동전이 모두 보드 밖으로 넘어간 경우
                    continue ;

                if (check1 + check2 == 1)  // 두 동전 중 하나만 보드에서 떨어진 경우
                    return (cnt);

                // 두 동전 모두 보드 안에 있는 경우
                if (!visited[ny1][nx1][ny2][nx2])
                {
                    // 다음 위치가 벽인 경우 제자리 그대로 다시 큐에 넣어주기
                    if (map[ny1][nx1] == '#')
                    {
                        ny1 = y1;
                        nx1 = x1;
                    }
                    if (map[ny2][nx2] == '#')
                    {
                        ny2 = y2;
                        nx2 = x2;
                    }
                    visited[ny1][nx1][ny2][nx2] = 1;

                    coin_set new_coin;

                    new_coin.coins[0] = {ny1, nx1};
                    new_coin.coins[1] = {ny2, nx2};
                    q.push(new_coin);
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

    input();
    cout << solve();
    return (0);
}