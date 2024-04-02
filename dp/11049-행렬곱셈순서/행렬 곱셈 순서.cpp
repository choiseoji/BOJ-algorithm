#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, r, c;
int ds[501];
int dp[501][501];  // dp[i][j]: i -> j 번째 행렬을 곱하는데 필요한 곱셈 연산의 최솟값

void input(void)
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> r >> c;
        ds[i] = r;
        ds[i+1] = c;
    }
}

void solve(void)
{
    // 초기화
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    //
    for(int i = 0; i <= N; i++)
    {
        dp[i][i] = 0;
    }
    for(int size = 0; size < N; size++)   // 몇개의 행렬을 곱할 것인지
    {
        for(int i = 1; i <= N - size; i++)
        {
            int a = i;   // start point
            int b = i + size;    // end point

            if (a == b)
                continue;

            for(int k = a; k < b; k++)  // 어디에서 split 할건지
            {
                dp[a][b] = min(dp[a][b], dp[a][k] + dp[k+1][b] + ds[a-1] * ds[k] * ds[b]);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();
    cout << dp[1][N];
    return (0);
}