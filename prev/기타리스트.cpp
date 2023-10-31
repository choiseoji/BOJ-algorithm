#include <iostream>
#include <vector>
using namespace std;

int ans = -1;
int N, S, M;  // 곡의 개수, 시작 볼륨, 최대 볼륨
bool dp[51][1001];
vector<int> volume;

int check_range(int n)
{
    if (n >= 0 && n <= M)
        return (1);
    return (0);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> N >> S >> M;
    for(int i = 0; i < N; i++)
    {
        int v; cin >> v;
        volume.push_back(v);
    }
    if (check_range(S - volume[0]))
        dp[0][S - volume[0]] = true;
    if (check_range(S + volume[0]))
        dp[0][S + volume[0]] = true;
    for(int i = 1; i < N; i++)
    {
        for(int j = 0; j <= M; j++)
        {
            if (dp[i - 1][j] == true)
            {
                if (check_range(j - volume[i]))
                    dp[i][j - volume[i]] = true;
                if (check_range(j + volume[i]))
                    dp[i][j + volume[i]] = true;
            }
        }
    }
    // 답 출력
    for(int i = 0; i <= M; i++)
    {
        if (dp[N - 1][i] == true)
            ans = max(ans, i);
    }
    cout << ans;
    return (0);
}