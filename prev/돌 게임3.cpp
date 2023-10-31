#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int dp[1001];  // 0: 상근이가 이김, 1: 창영이가 이김

    cin >> N;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 0;
    dp[4] = 0;
    for(int i = 5; i <= N; i++)
    {
        // 내(상근)이가 마지막에 1, 3, 4를 가져가는 경우 (i - 1, 3, 4)는 창영이가 이겼어야 함)
        if (dp[i - 1] == 1 || dp[i - 3] == 1 || dp[i - 4] == 1)
            dp[i] = 0;
        else
            dp[i] = 1;
    }
    if (dp[N] == 0)
        cout << "SK";
    else
        cout << "CY";
    return (0);
}

// dp[1] = 1 (0)
// dp[2] = 1 + 1 (1)
// dp[3] = 3 (0)
// dp[4] = 4 (0)
// dp[5] = 4 + 1 (1)
// dp[6] = 4 + 1 + 1 (0)
// dp[7] = 4 + 3 (1)
// dp[8] = 4 + 4 (1)
// dp[9] = 4 + 4 + 1 (0)
// dp[10] = 4 + 4 + 1 + 1 (1)
