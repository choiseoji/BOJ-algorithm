#include <iostream>
using namespace std;

int n, ans;
int arr[100001];
int dp[100001][2];  // 0: 빼지 않은, 1: 뺀

void input(void)
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void solve(void)
{
    dp[0][0] = arr[0];
    dp[0][1] = arr[0];
    ans = arr[0];
    for(int i = 1; i < n; i++)
    {
        // 현재 자신과 여태까지 더해진 수에 나를 더한 수 중 최댓값 고르기
        dp[i][0] = max(arr[i], dp[i - 1][0] + arr[i]);
        // 나 자신을 뺀 경우와 포함한 경우 중 최댓값 고르기
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
}

int main(void)
{
    input();
    solve();
    cout << ans;
    return (0);
}