#include <iostream>
#include <vector>
using namespace std;

int V;
int a, b, c;
int res, point;
int visited[100001];
vector<pair<int, int>> v[100001];  // 정점, 가중치

void input(void)
{
    cin >> V;
    while (V--)
    {
        cin >> a;
        while (1)
        {
            cin >> b;
            if (b == -1)
                break ;
            cin >> c;
            v[a].push_back({b ,c});
            v[b].push_back({a ,c});
        }
    }
}

void init(void)
{
    for (int i = 0; i < 100001; i++) {
        visited[i] = 0;
    }
}

void dfs(int node, int dist)
{
    if (visited[node])
        return ;
    visited[node] = 1;
    if (res < dist)
    {
        res = dist;
        point = node;
    }

    for(int i = 0; i < v[node].size(); i++)
    {
        dfs(v[node][i].first, dist + v[node][i].second);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    dfs(1, 0);
    init();
    dfs(point, 0);
    cout << res;
    return (0);
}