#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int ans;
int N, M, D;  // D : 공격 거리 제한
int map[15][15];
int origin[15][15];
bool visited[15][15];
vector<int> place;
vector<pair<int, int>> killed;
bool visited2[15][15];
int dx[3] = {-1, 0, 1};
int dy[3] = {0, -1, 0};

void input(void)
{
    cin >> N >> M >> D;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> origin[i][j];
        }
    }
}

void copy_map(void)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            map[i][j] = origin[i][j];
        }
    }
}

int is_end(void)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if (map[i][j] == 1)
                return (0);
        }
    }
    return (1);
}

void move_enemy(void)
{
    // 일단 제일 밑에 있는 칸은 다 0으로 바꿔주기
    for(int i = 0; i < M; i++)
    {
        map[N - 1][i] = 0;
    }
    // 밑에서부터 확인해주기
    for(int i = N - 1; i > 0; i--)
    {
        for(int j = 0; j < M; j++)
        {
            if (map[i - 1][j] == 1)
            {
                map[i][j] = 1;
                map[i - 1][j] = 0;
            }
        }
    }
}

void init_visited(void)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            visited[i][j] = false;
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            visited2[i][j] = false;
        }
    }
}

void bfs(int idx)
{
    int cnt;
    int q_size;
    queue<pair<int, int>> q;

    cnt = 0;
    q.push({N, idx});
    while (!q.empty())
    {
        if (cnt == D)
            break ;
        cnt++;
        q_size = q.size();
        while (q_size--)
        {
            int x = q.front().second;
            int y = q.front().first;
            q.pop();

            for(int i = 0; i < 3; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[ny][nx])
                {
                    visited[ny][nx] = true;
                    q.push({ny, nx});

                    if (map[ny][nx] == 1)
                    {
                        killed.push_back({ny, nx});
                        return ;
                    }
                }
            }
        }
    }
}

int start_game(void)
{
    int cnt_kill = 0;

    while (!is_end())
    {
        // 적 공격하기
        for(int i = 0; i < place.size(); i++)
        {
            init_visited();
            bfs(place[i]);
        }
        // 공격할 적 중복 체크
        for(int i = 0; i < killed.size(); i++)
        {
            if (!visited2[killed[i].first][killed[i].second])
            {
                visited2[killed[i].first][killed[i].second] = true;
                map[killed[i].first][killed[i].second] = 0;
                cnt_kill++;
            }
        }
        killed.clear();
        // 적 밑으로 이동
        move_enemy();
    }
    return (cnt_kill);
}

void get_three_place(int x)
{
    int res;

    if (place.size() == 3)
    {
        copy_map();
        res = start_game();
        ans = max(ans, res);
        return ;
    }

    for(int i = x; i < M; i++)
    {
        place.push_back(i);
        get_three_place(i + 1);
        place.pop_back();
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    get_three_place(0);
    cout << ans;
    return (0);
}
