#include <iostream>
#include <vector>
using namespace std;

int N, H, D;  // H: 체력, D: 우산 내구도
int ans = -1;
char map[504][504];
bool visited[11];  // 우산 있는 위치 방문 여부
vector<pair<int, int>> start;
vector<pair<int, int>> safe;
vector<pair<int, int>> umbrella;

void input(void)
{
    cin >> N >> H >> D;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'S')
                start.push_back({i, j});
            else if (map[i][j] == 'E')
                safe.push_back({i, j});
            else if (map[i][j] == 'U')
                umbrella.push_back({i, j});
        }
    }
}

int go_safe_zone(int sx, int sy, int h, int d)
{
    int nx = safe[0].second;
    int ny = safe[0].first;

    int dis = abs(sx - nx) + abs(sy - ny) - 1;
    int um = d - dis;
    
    if (um > 0)
        return (dis + 1);
    if (um <= 0 && h + um > 0)
        return (dis + 1);
    return (0);
}

void bt(int sx, int sy, int h, int d, int cnt)
{
    int dis;
    dis = go_safe_zone(sx, sy, h, d);
    if (dis > 0)
    {
        if (ans == -1)
            ans = cnt + dis;
        else
            ans = min(ans, cnt + dis);
        return ;
    }

    for(int i = 0; i < umbrella.size(); i++)
    {
        if (!visited[i])
        {
            // 체력 계산해서 이 위치로 이동해도 되면 visit 표시하고 이동해주기
            int nx = umbrella[i].second;
            int ny = umbrella[i].first;

            dis = abs(sx - nx) + abs(sy - ny) - 1;  // 우산이 있는 자리는 빼주고, 진짜 이동할 거리를 구해준다.
            int um = d - dis;  // 우산 쓰고 갈 수 있는 거리

            visited[i] = true;
            if (um > 0)  // um이 양수이면 안전하게 갈 수 있음
                bt(nx, ny, h, D, cnt + dis + 1);
            else if (um <= 0)  // um이 음수면 중간엔 우산 없이 가야함. 체력 계산해서 양수면 다음으로 가줌
            {
                if (h + um > 0)
                    bt(nx, ny, h + um - 1, D, cnt + dis + 1);
            }
            visited[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    bt(start[0].second, start[0].first, H, 0, 0);
    cout << ans;
    return (0);
}