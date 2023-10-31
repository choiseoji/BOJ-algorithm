#include <iostream>
using namespace std;

/**
 * dp[i] : i원을 만들기 위해 필요한 동전의 개수
*/

int T;
int N, M;
int coin[21];
int dp[10001];

void init()
{
    for(int i = 1; i <= M; i++)
    {
        dp[i] = 0;
    }
}

void solve()
{
    dp[0] = 1;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            if (j - coin[i] >= 0)
                dp[j] += dp[j - coin[i]];
        }
    }
    cout << dp[M] << "\n";
}

int main(void)
{
    cin >> T;
    while (T--)
    {
        cin >> N;  // 동전 개수
        for(int i = 1; i <= N; i++)
        {
            cin >> coin[i];
        }
        cin >> M;
        init();
        solve();
    }
    return (0);
}