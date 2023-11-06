#include <iostream>
#include <vector>
using namespace std;

int ans;
int n, m;  // 동기의 수, 리스트 길이
vector<int> f[502];
bool visited[502];

void input(void)
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;

        cin >> a >> b;
        f[a].push_back(b);
        f[b].push_back(a);
    }
}

// 친구의 친구
void find_friend(int idx)
{
    for(int i = 0; i < f[idx].size(); i++)
    {
        if (!visited[f[idx][i]])
        {
            visited[f[idx][i]] = true;
            ans++;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    // 상근이의 친구들부터 확인
    visited[1] = true;
    for(int i = 0; i < f[1].size(); i++)
    {
        if (!visited[f[1][i]])
        {
            visited[f[1][i]] = true;
            ans++;
        }
    }
    // 상근이의 친구의 친구 확인
    for(int i = 0; i < f[1].size(); i++)
    {
        find_friend(f[1][i]);
    }
    cout << ans;
    return (0);
}