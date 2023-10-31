#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    long long dp[1000001];
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i < 1000001; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
    }
    cin >> T;
    while (T--)
    {
        int n; cin >> n;
        cout << dp[n] << "\n";
    }
    return (0);
}
