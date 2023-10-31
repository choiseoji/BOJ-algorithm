#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int dp[1000001];
    int ans[1000001];

    cin >> N;
    dp[1] = 0;
    ans[1] = 1;
    for(int i = 2; i <= N; i++)
    {
        dp[i] = dp[i - 1] + 1;
        ans[i] = i - 1;
        if (i % 2 == 0)
        {
            if (dp[i / 2] < dp[i])
            {
                dp[i] = dp[i / 2] + 1;
                ans[i] = i / 2;
            }
        }
        if (i % 3 == 0)
        {
            if (dp[i / 3] < dp[i])
            {
                dp[i] = dp[i / 3] + 1;
                ans[i] = i / 3;
            }
        }
    }
    cout << dp[N] << "\n";
    if (N != 0)
        cout << N << " ";
    while (N != 1)
    {
        N = ans[N];
        cout << N << " ";
    }
    return (0);
}