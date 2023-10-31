/**
 * 자료구조, 그래프 이론, 트리, 분리 집합
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;  // 뉴런의 개수, 시냅스의 개수
int u, v;
int ans, tree = 0;
bool visited[100002];
int parent[100002];
vector<int> n[100002];

int bfs(int i)
{
    int cnt = 0;

    queue<int> q;
    q.push(i);
    visited[i] = true;
    parent[i] = -1;  // 이 노드가 부모
    while (!q.empty())
    {
        int ns = q.front();
        q.pop();

        for(int k = 0; k < n[ns].size(); k++)
        {
            if (parent[ns] == n[ns][k])  // 부모가 같다면
                continue;
            if (visited[n[ns][k]])
            {
                cnt += 1;
                continue;
            }
            q.push(n[ns][k]);
            visited[n[ns][k]] = true;
            parent[n[ns][k]] = ns;
        }
    }
    return (cnt / 2);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        cin >> u >> v;
        n[u].push_back(v);
        n[v].push_back(u);
    }
    for(int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            tree++;   // 묶여져 있는 그룹 개수 세주기
            ans += bfs(i);  // 넘겨주는 인자가 시작 뉴런, 사이클의 개수 세기
        }
    }
    cout << ans + (tree - 1);
    return (0);
}
