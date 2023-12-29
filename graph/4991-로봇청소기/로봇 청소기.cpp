#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int w, h;
int start_idx;
char map[21][21];
int dist[21][21];  // dist[i][j] : i에서 j까지의 거리
int min_value = 0x3f3f3f3f;
bool visited2[500];
vector<int> seq;
vector<pair<int ,int>> loc;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void input(void)
{
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'o')
            {
                start_idx = loc.size();
                loc.push_back({i, j});
            }
            else if (map[i][j] == '*')
                loc.push_back({i, j});
        }
    }
}

void init(void)
{
    min_value = 0x3f3f3f3f;
    for(int i = 0; i < 500; i++)
    {
        visited2[i] = false;
    }
    seq.clear();
    loc.clear();
}

// i 노드부터 j 노드까지의 거리
int bfs(int i, int j)
{
    int cnt = 0;
    bool visited[21][21];
    queue<pair<int, int>> q;
    q.push({loc[i].first, loc[i].second});  // 시작 위치
    for(int i = 0; i < 21; i++)
    {
        for(int j = 0; j < 21; j++)
        {
            visited[i][j] = false;
        }
    }

    while (!q.empty())
    {
        cnt++;
        int q_size = q.size();

        while (q_size--)
        {
            int x = q.front().second;
            int y = q.front().first;
            q.pop();

            if (x == loc[j].second && y == loc[j].first)
                return (cnt - 1);

            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < w && ny >= 0 && ny < h && !visited[ny][nx])
                {
                    if (map[ny][nx] == 'x')
                        continue;
                    q.push({ny, nx});
                    visited[ny][nx] = true;
                }
            }
        }
    }
    return (501);  // 엄청 큰 수..
}

// 더러운 곳에서 더러운 곳까지의 거리, bfs로 구하기
void get_dist(void)
{
    for(int i = 0; i < loc.size(); i++)
    {
        for(int j = 0; j < loc.size(); j++)
        {
            // i에서 j까지의 거리
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = bfs(i, j);
        }
    }
}

int solve(void)
{
    int cur;
    int nxt;
    int value = 0;

    for(int i = 1; i < seq.size(); i++)
    {
        cur = seq[i - 1];
        nxt = seq[i];
        value += dist[cur][nxt];
    }
    return (value);
}

void get_seq(void)
{
    int value;

    if (seq.size() == loc.size())
    {
        value = solve();
        min_value = min(value, min_value);
        return ;
    }

    for(int i = 0; i < loc.size(); i++)
    {
        if (!visited2[i])
        {
            seq.push_back(i);
            visited2[i] = true;
            get_seq();
            seq.pop_back();
            visited2[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (1)
    {
        cin >> w >> h;
        if (w == 0 && h == 0)
            break ;
        init();
        input();
        get_dist();
        seq.push_back(start_idx);   // 시작점 노드부터 넣어주기
        visited2[start_idx] = true;
        get_seq();
        if (min_value > 500)
            cout << -1 << "\n";
        else
            cout << min_value << "\n";
    }
    return (0);
}