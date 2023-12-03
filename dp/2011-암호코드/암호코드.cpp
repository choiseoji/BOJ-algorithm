#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string num;
    long long dp[5001];

    cin >> num;
    dp[0] = dp[1] = 1;
    if (num[0] == '1' || (num[0] == '2' && num[1] <= '6'))
        dp[1] += 1;
    for(int i = 2; i < num.size(); i++)
    {
        // 현재 글자만 
        dp[i] = dp[i - 1];
        // 앞에 글자까지 한 글자로 보면
        if (num[i - 1] == '1' || (num[i - 1] == '2' && num[i] <= '6'))
            dp[i] += (dp[i - 2] % 1000000);
    }
    cout << dp[num.size() - 1];
    return (0);
}
