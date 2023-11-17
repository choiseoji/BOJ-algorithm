#include <iostream>
#include <vector>
using namespace std;

int N, R, Q;  // 정점의 수, 루트의 번호, 쿼리의 수
int u, v;
vector<int> tree[100001];
bool visited[100001];
int dp[100001];

void input(void)
{
    cin >> N >> R >> Q;
    for(int i = 0; i < N - 1; i++)
    {
        cin >> u >> v;
        tree[u].push_back(v);
        if (u == R)
            tree[v].push_back(-1);
        else
            tree[v].push_back(u);
    }
}

void output(void)
{
    for(int i = 0; i < Q; i++)
    {
        cin >> u;
        cout << dp[u] << "\n";
    }
}

int dfs(int u)   // 해당 노드의 정점의 개수 cnt
{
    int cnt = 1;

    visited[u]  = true;
    if (u == -1)
        return (0);

    for(int i = 0; i < tree[u].size(); i++)
    {
        if (!visited[tree[u][i]])
            cnt += dfs(tree[u][i]);
    }
    dp[u] = cnt;
    return (cnt);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    dfs(R);    // 싸이클 처리를 해줘야 함.
    output();
    return (0);
}