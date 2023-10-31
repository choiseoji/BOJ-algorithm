#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int ans = 0;
    long long dp[1001][10]; // dp[i][j] : 길이가 i이고, j로 시작하는 오르막 수의 개수

    cin >> N;
    for(int i = 0; i < 10; i++)
    {
        dp[1][i] = 1;
    }
    for(int i = 2; i <= N; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            dp[i][j] = 0;
            for(int k = j; k < 10; k++)
            {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= 10007;
            }
        }
    }
    for(int i = 0; i < 10; i++)
    {
        ans += dp[N][i];
    }
    cout << ans % 10007;
    return (0);
}

/**
 * dp[2][0] : 0으로 시작하고 길이가 2인 오르막 수의 개수 = dp[1][0 ~ 9]의 총합
 * dp[2][1] : 1로 시작하고 길이가 2인 오르막 수의 개수 = dp[1][1 ~ 9] 의 총합
 * -> 1로 시작하면 길이는 하나 짧지만 1부터 시작하는 수를 1 뒤에 추가해주면 된다.
*/
