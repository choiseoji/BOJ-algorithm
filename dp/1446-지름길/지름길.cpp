#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, D;
int from, to, dist;
int dp[10001];
vector<pair<int, int>> v[10001];    // v[to] = {from, dist}

void input(void)
{
    cin >> N >> D;

    for(int i = 0; i < N; i++)
    {
        cin >> from >> to >> dist;
        v[to].push_back({from, dist});
    }
}

void init(void)
{
    for(int i = 0; i <= D; i++)
    {
        dp[i] = 0x3f3f3f3f;
    }
}

void solve(void)
{
    dp[0] = 0;
    for(int i = 1; i <= D; i++)
    {
        if (v[i].size() == 0)
        {
            dp[i] = dp[i - 1] + 1;
        }
        else
        {
            for(int j = 0; j < v[i].size(); j++)
            {
                dp[i] = min(dp[i], min(dp[i - 1] + 1, dp[v[i][j].first] + v[i][j].second));
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    init();
    solve();
    cout << dp[D];
    return (0);
}