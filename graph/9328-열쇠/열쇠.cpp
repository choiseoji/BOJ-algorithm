#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int t;
int cnt;
int w, h;
int key[26];
char map[102][102];
bool visited[102][102];
queue<pair<int, int>> q;
vector<pair<int, int>> door[26];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void init(void)
{
    cnt = 0;
    for(int i = 0; i < 102; i++)
    {
        for(int j = 0; j < 102; j++)
        {
            map[i][j] = '*';
            visited[i][j] = false;
        }
    }
    for(int i = 0; i < 26; i++)
    {
        door[i].clear();
        key[i] = 0;
    }
}

void input(void)
{
    cin >> h >> w;
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cin >> map[i][j];
        }
    }

    // 이미 가지고 있는 key
    string k;

    cin >> k;
    if (k != "0")
    {
        for(int i = 0; i < k.size(); i++)
        {
            key[k[i] - 'a'] = 1;
        }
    }
}

void    find_entrance(void)
{
    // 입구 찾기
    for(int i = 0; i < h; i++)
    {
        if (map[i][0] >= 'A' && map[i][0] <= 'Z')  // 문을 만나면 key 있는지 확인
        {
            if (key[map[i][0] - 'A'] == 1)  // key 있으면 방문
            {
                q.push({i, 0});
                visited[i][0] = true;
            }
            else
                door[map[i][0] - 'A'].push_back({i, 0});
        }
        else if (map[i][0] != '*')  // 벽이 아니면
        {
            q.push({i, 0});
            visited[i][0] = true;
            if (map[i][0] == '$')  // 문서이면 cnt++
                cnt++;
            if (map[i][0] >= 'a' && map[i][0] <= 'z')  // 열쇠이면 표시
                key[map[i][0] - 'a'] = 1;
        }
        if (map[i][w - 1] >= 'A' && map[i][w - 1] <= 'Z')
        {
            if (key[map[i][w - 1] - 'A'] == 1)
            {
                q.push({i, w - 1});
                visited[i][w - 1] = true;
            }
            else
                door[map[i][w - 1] - 'A'].push_back({i, w - 1});
        }
        else if (map[i][w - 1] != '*')
        {
            q.push({i, w - 1});
            visited[i][w - 1] = true;
            if (map[i][w - 1] == '$')
                cnt++;
            if (map[i][w - 1] >= 'a' && map[i][w - 1] <= 'z')
                key[map[i][w - 1] - 'a'] = 1;
        }
    }
    for(int j = 1; j < w - 1; j++)
    {
        if (map[0][j] >= 'A' && map[0][j] <= 'Z')
        {
            if (key[map[0][j] - 'A'] == 1)
            {
                q.push({0, j});
                visited[0][j] = true;
            }
            else
                door[map[0][j] - 'A'].push_back({0, j});
        }
        else if (map[0][j] != '*')
        {
            q.push({0, j});
            visited[0][j] = true;
            if (map[0][j] == '$')
                cnt++;
            if (map[0][j] >= 'a' && map[0][j] <= 'z')
                key[map[0][j] - 'a'] = 1;
        }
        if (map[h - 1][j] >= 'A' && map[h - 1][j] <= 'Z')
        {
            if (key[map[h - 1][j] - 'A'] == 1)
            {
                q.push({h - 1, j});
                visited[h - 1][j] = true;
            }
            else
                door[map[h - 1][j] - 'A'].push_back({h - 1, j});
        }
        else if (map[h - 1][j] != '*')
        {
            q.push({h - 1, j});
            visited[h - 1][j] = true;
            if (map[h - 1][j] == '$')
                cnt++;
            if (map[h - 1][j] >= 'a' && map[h - 1][j] <= 'z')
                key[map[h - 1][j] - 'a'] = 1;
        }
    }
}

void solve(void)
{
    while (!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < w && ny >= 0 && ny < h && map[ny][nx] != '*' && !visited[ny][nx])
            {
                // '$' 만나면 문서 획득 + 방문
                if (map[ny][nx] == '$')
                {
                    cnt++;
                }
                // 소문자 알파벳 만나면 key 획득 + 방문
                // -> door[key]에 있는 좌표 큐에 넣어주기 + 큐에 넣은 좌표들은 door[key]에서 삭제해주기
                else if (map[ny][nx] >= 'a' && map[ny][nx] <= 'z')
                {
                    int idx = map[ny][nx] - 'a';
                    key[idx] = 1;
                    for(int i = 0; i < door[idx].size(); i++)
                    {
                        if (!visited[door[idx][i].first][door[idx][i].second])
                        {
                            q.push({door[idx][i].first, door[idx][i].second});
                            visited[door[idx][i].first][door[idx][i].second] = true;
                        }
                    }
                    door[idx].clear();
                }
                // 대문자 알파벳 만나면 key 확인
                // 1. key가 있다면 방문
                // 2. key가 없다면 door[key]에 좌표 넣어두기
                else if (map[ny][nx] >= 'A' && map[ny][nx] <= 'Z')
                {
                    int idx = map[ny][nx] - 'A';
                    if (key[idx] == 0)
                    {
                        door[idx].push_back({ny, nx});
                        continue;
                    }
                }
                q.push({ny, nx});
                visited[ny][nx] = true;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--)
    {
        init();
        input();
        find_entrance();
        solve();
        cout << cnt << "\n";
    }
    return (0);
}