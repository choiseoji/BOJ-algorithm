#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N, M, num;
vector<int> v[10001];
vector<pair<int, int>> cnt;  // 컴퓨터 번호, 몇개 신뢰하는지
int visited[10001];

void input(void)
{
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int a, b;

        cin >> a >> b;
        v[b].push_back(a);
    }
}

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return (a.first < b.first);
    return (a.second > b.second);
}

int dfs(int cur)
{
    int cnt = 0;

    if (v[cur].empty())
        return (0);
    for(int i = 0; i < v[cur].size(); i++)
    {
        if (!visited[v[cur][i]])
        {
            visited[v[cur][i]] = 1;
            cnt++;
            cnt += dfs(v[cur][i]);
        }
    }
    return (cnt);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    // 모든 컴퓨터 검사
    for(int i = 1; i <= N; i++)
    {
        visited[i] = 1;
        num = dfs(i);
        cnt.push_back({i, num});
        memset(visited, 0, sizeof(visited));
    }
    // 정렬
    sort(cnt.begin(), cnt.end(), compare);
    // 출력
    for(int i = 0; i < cnt.size(); i++)
    {
        if (i == 0 || cnt[i].second == cnt[0].second)
            cout << cnt[i].first << " ";
        else
            break ;
    }
    return (0);
}
