#include <iostream>
#include <vector>
using namespace std;

int ans;
int N, K, W, V;
int dp[101][100001];
vector<pair<int, int>> v;

void input(void)
{
    cin >> N >> K;  // 물품의 수, 버틸 수 있는 무게

    v.push_back({0, 0});
    for(int i = 0; i < N; i++)
    {
        cin >> W >> V;
        v.push_back({W, V});   // 물건의 무게, 가치
    }
}

void solve(void)
{
    for(int i = 1; i < v.size(); i++)
    {
        for(int j = 1; j <= K; j++)
        {
            dp[i][j] = 0;

            if (j - v[i].first >= 0)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].first] + v[i].second);
            else
                dp[i][j] = dp[i-1][j];
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << "\n";
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();
    return (0);
}