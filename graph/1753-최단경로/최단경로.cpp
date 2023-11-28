#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E, K;
int u, v, w;
int d[300001];
vector<pair<int, int>> adj[300001];  // 가중치, 정점

void input(void)
{
    cin >> V >> E >> K;
    for(int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
}

void solve(void)
{
    fill(d, d + V + 1, 0x3f3f3f3f);
    d[K] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({d[K], K});
    while (!pq.empty())
    {
        int node = pq.top().second;
        int price = pq.top().first;
        pq.pop();

        if (d[node] != price)
            continue;
        
        for(int i = 0; i < adj[node].size(); i++)
        {
            if (d[adj[node][i].second] <= d[node] + adj[node][i].first)
                continue;
            d[adj[node][i].second] = d[node] + adj[node][i].first;
            pq.push({d[adj[node][i].second], adj[node][i].second});
        }
    }
}

void output(void)
{
    for(int i = 1; i <= V; i++)
    {
        if (d[i] != 0x3f3f3f3f)
            cout << d[i] << "\n";
        else
            cout << "INF" << "\n";
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