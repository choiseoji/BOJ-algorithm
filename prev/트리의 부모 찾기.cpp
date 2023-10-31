#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> tree[100001];
vector<int> ans[100001];
bool visited[100001];

void go_child(int parent)
{
    for(int i = 0; i < tree[parent].size(); i++)
    {
        if (!visited[tree[parent][i]])
        {
            ans[tree[parent][i]].push_back(parent);
            visited[tree[parent][i]] = true;
            go_child(tree[parent][i]);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N - 1; i++)
    {
        int a, b;

        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    for(int j = 0; j < tree[1].size(); j++)
    {
        ans[tree[1][j]].push_back(1);
        visited[tree[1][j]] = true;
        go_child(tree[1][j]);
    }
    for(int i = 2; i <= N; i++)
    {
        cout << ans[i].back() << "\n";
    }
    return (0);
}
