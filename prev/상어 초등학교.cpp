#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct st
{
    int num;
    int f[4];
    int x, y;
};

int N;
int ans;
int map[23][23];
st student[400];
vector<st> v;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// 입력값
void input(void)
{
    cin >> N;
    for(int i = 0; i < N * N; i++)
    {
        int n;
        int a, b, c, d;

        cin >> n >> a >> b >> c >> d;
        student[i].num = n;
        student[i].f[0] = a;
        student[i].f[1] = b;
        student[i].f[2] = c;
        student[i].f[3] = d;
        student[i].x = 0;
        student[i].y = 0;
        v.push_back(student[i]);
    }
}

bool compare(const pair<pair<int, int>, pair<int, int>> &a, const pair<pair<int, int>, pair<int, int>> &b)
{
    if (a.second.first == b.second.first)
    {
        if (a.second.second == b.second.second)
        {
            if (a.first.first == b.first.first)
                return (a.first.second < b.first.second);
            return (a.first.first < b.first.first);
        }
        return (a.second.second > b.second.second);
    }
    return (a.second.first > b.second.first);
}

int like_friend(int nx, int ny, int shark)
{
    if (map[ny][nx] == v[shark].f[0])
        return (1);
    if (map[ny][nx] == v[shark].f[1])
        return (1);
    if (map[ny][nx] == v[shark].f[2])
        return (1);
    if (map[ny][nx] == v[shark].f[3])
        return (1);
    return (0);
}

// 상어가 어디 앉을지
void find_sit(int shark)
{
    vector<pair<pair<int, int>, pair<int, int>>> can_sit;  // 좌표, 인접한 친구 수, 빈칸 수

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if (map[i][j] == 0)  // 빈자리 중에서
            {
                int x = j;
                int y = i;
                int cnt = 0;
                int empty = 0;

                for(int k = 0; k < 4; k++)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx >= 1 && nx <= N && ny >= 1 && ny <= N)
                    {
                        if (like_friend(nx, ny, shark))  // 인접한 친구 수 cnt
                            cnt++;
                        if (map[ny][nx] == 0)  // 인접한 빈칸 수 cnt
                            empty++;
                    }
                }
                can_sit.push_back({{y, x}, {cnt, empty}});
            }
        }
    }
    sort(can_sit.begin(), can_sit.end(), compare);  // can_sit 정렬
    map[can_sit[0].first.first][can_sit[0].first.second] = v[shark].num;
    v[shark].x = can_sit[0].first.second;
    v[shark].y = can_sit[0].first.first;
}

void solve(void)
{
    // 상어 앉을 자리 찾기
    for(int i = 0; i < N * N; i++)
    {
        // find_sit
        find_sit(i);
    }
    // 상어 만족도 계산
    for(int i = 0; i < N * N; i++)
    {
        int x = v[i].x;
        int y = v[i].y;
        int cnt = 0;

        for(int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N)
            {
                if (like_friend(nx, ny, i))
                    cnt++;
            }
        }
        if (cnt == 1)
            ans += 1;
        else if (cnt == 2)
            ans += 10;
        else if (cnt == 3)
            ans += 100;
        else if (cnt == 4)
            ans += 1000;
    }
    cout << ans;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();
    return (0);
}
