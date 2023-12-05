#include <iostream>
#include <vector>
using namespace std;

int n;
int point, res;
int a, b, c;
bool visited[10001];
vector<pair<int ,int>> v[10001];  // 자식, 가중치

void input(void)
{
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        cin >> a >> b >> c;  // 부모, 자식, 가중치
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
}

void dfs(int node, int dist)
{
    if (visited[node])
        return ;
    visited[node] = true;
    if (res < dist)  // 가장 멀리 있는 점 찾기
    {
        res = dist;
        point = node;
    }

    for(int i = 0; i < v[node].size(); i++)  // node의 자식 노드 확인
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
    fill(visited, visited + n + 1, 0);
    dfs(point, 0);
    cout << res;
    return (0);
}