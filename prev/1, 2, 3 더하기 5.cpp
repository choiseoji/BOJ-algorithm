#include <iostream>
using namespace std;

int T, num;
int dp[100001][4];  // dp[i][j] : 합이 i 가 되는데 가장 마지막에 더한게 j인 경우

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;  // 2 + 1
    dp[3][2] = 1;  // 1 + 2
    dp[3][3] = 1;  // 3

    while (T--)
    {
        cin >> num;
        for(int i = 4; i <= num; i++)
        {
            dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000009;
            dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;
            dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % 1000000009;
        }
        cout << ((dp[num][1] + dp[num][2]) % 1000000009 + dp[num][3]) % 1000000009 << "\n";
    }
    return (0);
}