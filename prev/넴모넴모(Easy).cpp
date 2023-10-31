#include <iostream>
using namespace std;

int N, M;
bool visited[27][27];

int solve(int x, int y)
{
    int ans = 0;

    if (x > M)
    {
        x = 1;
        y += 1;
    }
    if (y > N)
        return (0);
    // 현재 자리네 넴모를 올렸을 때, 2 * 2가 되지 않는 경우만
    // x가 증가하는 순으로 검사하니깐
    // x - 1, y - 1, (x - 1, y - 1)을 검사해야 함.
    if (!visited[y - 1][x] || !visited[y][x - 1] || !visited[y - 1][x - 1])
    {
        visited[y][x] = true;
        ans += (1 + solve(x + 1, y));
        visited[y][x] = false;
    }
    ans += solve(x + 1, y);
    return (ans);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    cout << solve(1, 1) + 1;
    return (0);
}