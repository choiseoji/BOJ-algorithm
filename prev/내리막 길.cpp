/**
 * 다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 깊이 우선 탐색
 * 메모 : dfs를 통해 풀었는데, 시간초과가 났다. 경로가 중복되는 경우를 dp배열에
 * 저장해두고 쓰는 방법으로 최적화를 했다.
*/
#include <iostream>
using namespace std;

int N, M;
int map[501][501];
int dp[501][501];

void input(void)
{
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            dp[i][j] = -1;   // -1로 초기화
        }
    }
}

int in_range(int x, int y)
{
    if (x >= 0 && x < M && y >= 0 && y < N)
        return (1);
    return (0);
}

int dfs(int x, int y)
{
    int ans;

    ans = 0;
    if ((y == N - 1) && (x == M - 1))
    {
        return (1);
    }
    if (dp[y][x] != -1)
        return (dp[y][x]);

    if (in_range(x, y - 1) && (map[y][x] > map[y - 1][x]))
        ans += dfs(x, y - 1);
    if (in_range(x + 1, y) && (map[y][x] > map[y][x + 1]))
        ans += dfs(x + 1, y);
    if (in_range(x, y + 1) && (map[y][x] > map[y + 1][x]))
        ans += dfs(x, y + 1);
    if (in_range(x - 1, y) && (map[y][x] > map[y][x - 1]))
        ans += dfs(x - 1, y);
    dp[y][x] = ans;   // 저장해두고 쓰기
    return (ans);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    cout << dfs(0, 0);   // 현재 좌표
    return (0);
}