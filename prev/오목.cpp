#include <iostream>
#include <vector>
using namespace std;

int map[20][20];
int x, y, nx, ny;
int dx[8] = {1, 0, 1, 1, -1, 0, -1, -1};
int dy[8] = {0, 1, 1, -1, 0, -1, -1, 1};
vector<pair<int, int>> v;

void input(void)
{
    for(int i = 1; i <= 19; i++)
    {
        for(int j = 1; j <= 19; j++)
        {
            cin >> map[i][j];
            if (map[i][j] != 0)
                v.push_back({i, j});
        }
    }
}

int range_check(int y, int x)
{
    if (x > 0 && x <= 19 && y > 0 && y <= 19)
        return (1);
    return (0);
}

int check_next(int y, int x, int ny, int nx, int dir)
{
    // 시작점의 반대편이 없고, 다음 좌표가 시작점하고 똑같은 경우
    if (!range_check(y + dy[dir + 4], x + dx[dir + 4])
        && (map[ny][nx] == map[y][x]))
        return (1);
    // 시작점의 반대편이 있고, 반대편은 시작점과 다르고 다음 좌표는 시작점하고 같은 경우
    if (range_check(y + dy[dir + 4], x + dx[dir + 4]) && (map[y + dy[dir + 4]][x + dx[dir + 4]] != map[y][x])
                && range_check(ny, nx) && (map[ny][nx] == map[y][x]))
            return (1);
    return (0);
}

int solve(void)
{
    for(int i = 0; i < v.size(); i++)
    {
        x = v[i].second;
        y = v[i].first;

        for(int dir = 0; dir < 4; dir++)
        {
            nx = x + dx[dir];
            ny = y + dy[dir];

            if (check_next(y, x, ny, nx, dir))
            {
                int cnt = 1;

                while (range_check(ny, nx) && (map[ny][nx] == map[y][x]))
                {
                    cnt++;
                    nx += dx[dir];
                    ny += dy[dir];
                }
                if (cnt == 5)
                {
                    cout << map[y][x] << "\n";
                    cout << y << " " << x;
                    return (0);
                }
            }
        }
    }
    cout << 0;
    return (0);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();
    return (0);
}