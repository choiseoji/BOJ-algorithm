#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int N, T;
vector<pair<int, int>> v;
map<int, bool> special;
int d[1001][1001];

void input(void)
{
    cin >> N >> T;
    for(int i = 1; i <= N; i++)
    {
        int s, x, y;

        cin >> s >> x >> y;
        v.push_back({x, y});
        if (s == 1)
            special[i] = true;
    }
}

void solve(void)
{
    // 다 무한대로 초기화
    for(int i = 0; i <= N; i++)
    {
        for(int j = 0; j <= N; j++)
        {
            d[i][j] = 0x3f3f3f3f;
        }
    }
    // 거리 계산해주기
    for(int i = 0; i < v.size(); i++)
    {
        int s = i + 1;
        int sx = v[i].first;
        int sy = v[i].second;
        for(int j = 0; j < v.size(); j++)
        {
            int e = j + 1;
            int ex = v[j].first;
            int ey = v[j].second;

            d[s][e] = abs(sx - ex) + abs(sy - ey);
            if (special[s] == true && special[e] == true)
                d[s][e] = min(d[s][e], T);
        }
    }
    // 최단거리
    for(int k = 1; k <= N; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

void output(void)
{
    int t;

    cin >> t;
    while (t--)
    {
        int s, e;

        cin >> s >> e;
        cout << d[s][e] << "\n";
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