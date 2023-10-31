/**
 * 문제 번호 : 13301번 - 타일 장식물
 * 알고리즘 분류 : 수학, 다이나믹 프로그래밍
*/

#include <iostream>
using namespace std;

int N;
long long t[81];
long long dp[81];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    dp[1] = 4;
    dp[2] = dp[1] + (2 * 1);
    dp[3] = dp[2] + (2 * 2);
    t[2] = 1;
    t[3] = 2;
    for(int i = 4; i <= N; i++)
    {
        t[i] = t[i - 1] + t[i - 2];
        dp[i] = dp[i - 1] + (2 * t[i]);
    }
    cout << dp[N];
    return (0);
}