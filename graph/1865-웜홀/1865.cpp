#include <iostream>
#include <vector>
using namespace std;

int T, N, M, W;
int s, e, t;
int dist[501];
vector<pair<pair<int, int>, int>> v;

void solve(void)
{
    int from, to, cost;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < v.size(); j++)
        {
            from = v[j].first.first;
            to = v[j].first.second;
            cost = v[j].second;

            if (dist[from] + cost < dist[to])
                dist[to] = dist[from] + cost;
        }
    }

    for(int i = 0; i < v.size(); i++)
    {
        from = v[i].first.first;
        to = v[i].first.second;
        cost = v[i].second;

        if (dist[from] + cost < dist[to])
        {
            cout << "YES\n";
            return ;
        }
    }
    cout << "NO\n";
}

int main(void)
{
    cin >> T;
    while (T--)
    {
        v.clear();
        cin >> N >> M >> W;   // 정점, 도로, 웜홀

        for(int i = 0; i < N; i++)
        {
            dist[i] = 0x3f3f3f3f;
        }
        for(int i = 0; i < M; i++)
        {
            cin >> s >> e >> t;
            v.push_back({{s, e}, t});
            v.push_back({{e, s}, t});
        }
        for(int i = 0; i < W; i++)
        {
            cin >> s >> e >> t;
            v.push_back({{s, e}, -t});   // 웜홀은 방향성 o
        }
        solve();
    }
    return (0);
}
