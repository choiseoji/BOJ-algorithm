#include <iostream>
using namespace std;

int n, t, s, e;
int arr[2001];
int dp[2001][2001];  // dp[s][e] : 구간 s ~ e 가 팰린드롬인지 표시

void input()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
}

void solve()
{
    // 시작과 끝이 같으면 무조건 팰린드롬
    for(int i = 1; i <= n; i++)
    {
        dp[i][i] = 1;
    }
    // 크기가 2인 경우 양 끝이 같으면 팰린드롬
    for(int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i + 1])
            dp[i][i + 1] = 1;
    }
    // 나머지 경우 팰린드롬 확인
    for(int i = n - 1; i >= 1; i--) // s, 현재 시작 위치보다 한칸 앞을 볼 거라서 뒤에서 부터 값을 넣어줬다. (뒤에 값 확인하려고)
    {
        for(int j = i + 2; j <= n; j++)  // e, 크기가 1, 2인 경우는 위에서 확인했으므로 i + 1을 끝 값의 시작으로 잡아주기
        {
            if (arr[i] == arr[j] && dp[i + 1][j - 1])
                dp[i][j] = 1;
            else
                dp[i][j] = 0;
        }
    }
}

void output()
{
    cin >> t;
    while (t--)
    {
        int s, e;
        
        cin >> s >> e;
        cout << dp[s][e] << "\n";
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();
    output();
    return (0);
}