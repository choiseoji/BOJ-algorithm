#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 0x3f3f3f3f

int N, M;   // 도시, 버스
int st, en, u, v, w;
int d[1001]; // 최단거리 테이블
vector<pair<int, int>> adj[1001];  // 비용, 정점 번호

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({w, v});  // 거리, 정점
    }
    cin >> st >> en;
    // solve
    fill(d, d + N + 1, INF);
    // pq : 비용, 노드
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    d[st] = 0;
    pq.push({d[st], st});
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
    // output
    cout << d[en];
    return (0);
}
