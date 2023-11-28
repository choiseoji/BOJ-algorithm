#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, E;  // 정점의 개수, 간선의 개수
long long res;
int a, b, c;
int v1, v2;  // 반드시 거쳐야 할 정점 2개
long long d[802];
vector<pair<int, int>> v[802];  // 비용, 정점
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void input(void)
{
    cin >> N >> E;
    for(int i = 0; i < E; i++)
    {
        cin >> a >> b >> c;
        v[a].push_back({c, b});
        v[b].push_back({c, a});
    }
    cin >> v1 >> v2;
}

void get_dist(int start)
{
    fill(d, d + N + 1, 0x3f3f3f3f);
    d[start] = 0;
    pq.push({d[start], start});
    while (!pq.empty())
    {
        int node = pq.top().second;
        int price = pq.top().first;
        pq.pop();

        if (d[node] != price)
            continue;
        for(int i = 0; i < v[node].size(); i++)
        {
            if (d[v[node][i].second] < price + v[node][i].first)
                continue;
            d[v[node][i].second] = price + v[node][i].first;
            pq.push({d[v[node][i].second], v[node][i].second});
        }
    }
}

int solve(void)
{
    // 1에서 v1이나 v2로 가는 최단거리
    get_dist(1);
    int to_v1 = d[v1];
    int to_v2 = d[v2];

    // v1과 v2 사이의 최단 거리
    get_dist(v1);
    long long v1_to_v2 = d[v2];

    // v1이나 v2에서 N까지 가는 최단 거리
    get_dist(v1);
    int v1_to_N = d[N];
    get_dist(v2);
    int v2_to_N = d[N];

    res = min(to_v1 + v1_to_v2 + v2_to_N, to_v2 +  v1_to_v2 + v1_to_N);
    res = min(res, (long long)0x3f3f3f3f);
    if (res >= 0x3f3f3f3f)
        return (0);
    return (1);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int have_route;

    input();
    have_route = solve();
    if (have_route)
        cout << res;
    else
        cout << -1;
    return (0);
}