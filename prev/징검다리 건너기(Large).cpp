#include <iostream>
using namespace std;

int N;
long long arr[5002];
long long dp[5002];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    //dp[i] : 경로의 대표값(i까지 오는 k의 최댓값) 중 최솟값
    dp[1] = 0;
    for(int i = 2; i <= N; i++)
    {
        dp[i] = 0x3f3f3f3f;
        for(int j = 1; j < i; j++)
        {
            dp[i] = min(dp[i], max(dp[j], (abs(arr[i] - arr[j]) + 1) * (i - j)));
        }
    }
    cout << dp[N];
    return (0);
}
