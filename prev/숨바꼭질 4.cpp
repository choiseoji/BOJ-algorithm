#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K;
queue<pair<int, int>> q;  // 위치 저장
vector<int> v;
int path[100001];  // i번째 자리에 가기 전 위치 저장 (경로 저장)
bool visited[100001];

void print_path(int cur)
{
    while (cur != -1)
    {
        v.push_back(cur);
        cur = path[cur];
    }
    for(int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i] << " ";
    }
}

void solve()
{
    while (!q.empty())
    {
        int cur = q.front().first;
        int t = q.front().second;
        q.pop();
        
        if (cur == K)
        {
            cout << t << "\n";
            print_path(cur);
            return ;
        }

        if (2 * cur >= 0 && 2 * cur <= 100000)
        {
            if (!visited[2 * cur])
            {
                visited[2 * cur] = true;
                path[2 * cur] = cur;
                q.push({2 * cur, t + 1});
            }
        }
        if (cur - 1 >= 0 && cur - 1 <= 100000)
        {
            if (!visited[cur - 1])
            {
                visited[cur - 1] = true;
                path[cur - 1] = cur;
                q.push({cur - 1, t + 1});
            }
        }
        if (cur + 1 >= 0 && cur + 1 <= 100000)
        {
            if (!visited[cur + 1])
            {
                visited[cur + 1] = true;
                path[cur + 1] = cur;
                q.push({cur + 1, t + 1});
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    q.push({N, 0});
    path[N] = -1;  // 처음 위치
    visited[N] = true;
    solve();
    return (0);
}