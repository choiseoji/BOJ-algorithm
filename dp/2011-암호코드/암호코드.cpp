#include <iostream>
using namespace std;

string num;
long long dp[5001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> num;

    if (num[0] == '0')
    {
        cout << 0;
        return (0);
    }

    dp[0] = dp[1] = 1;    // num은 인덱스 0부터 시작, dp는 1부터 시작

    for(int i = 2; i <= num.size(); i++)
    {
        // 현재가 0이 아니라면 dp[i - 1]의 경우의 수 그대로
        if (num[i - 1] != '0')
            dp[i] = dp[i - 1] % 1000000;

        // 현재와 이전 숫자가 하나의 알파벳이 된다면 dp[i - 2]의 경우의 수 받기
        if (num[i - 2] == '1' || (num[i - 2] == '2' && num[i - 1] <= '6'))
            dp[i] = (dp[i] + dp[i - 2]) % 1000000;
    }
    cout << dp[num.size()];
    return (0);
}
