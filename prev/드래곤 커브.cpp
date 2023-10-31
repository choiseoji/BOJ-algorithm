#include <iostream>
using namespace std;

int N;
int ans;
int x, y, d, g;
vector<int> v;
int map[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void check_ans()
{
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            if (map[i][j] == 1)
            {
                if (map[i + 1][j] == 1
                    && map[i][j + 1] == 1
                    && map[i + 1][j + 1] == 1)
                    ans ++;
            }
        }
    }
}
// 전 세대의 끝 점과 현 세대 정보를 넘겨줌
// 방향 정보를 벡터의 뒤에서부터 꺼내서
// 끝점위치 + (꺼낸 방향 90도 회전시킨 방향) = 새로운 끝점 위치
// 계속 끝점의 위치를 갱신해 나가면 된다.
void solve(int x, int y, int cur_g)
{
    int v_size;

    if (cur_g == g)
    {
        v.clear();
        return ;
    }

    v_size = v.size();
    for(int i = v.size() - 1; i >= 0; i--)
    {
        int dir = v[i];

        if (dir == 0)
        {
            x += dx[1];
            y += dy[1];
            v.push_back(1);
        }
        else if (dir == 1)
        {
            x += dx[2];
            y += dy[2];
            v.push_back(2);
        }
        else if (dir == 2)
        {
            x += dx[3];
            y += dy[3];
            v.push_back(3);
        }
        else if (dir == 3)
        {
            x += dx[0];
            y += dy[0];
            v.push_back(0);
        }
        map[x][y] = 1;
    }
    cur_g++;
    solve(x, y, cur_g);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    while (N--)
    {
        cin >> x >> y >> d >> g;

        map[x][y] = 1;  //  0세대 시작점
        map[x + dx[d]][y + dy[d]] = 1; // 0세대 끝점
        v.push_back(d);
        solve(x + dx[d], y + dy[d], 0);
    }
    check_ans();
    cout << ans;
    return (0);
}