#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, X;   // 학생 수, 도로 수(단반향), X번 마을
int a, b, c;   // 도로 시작점, 끝점, 소요시간
int ans;
int d[1001];
int toX[1001];
int toS[1001];
vector<pair<int, int>> v[1001];
// 비용, 정점
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void input(void)
{
    cin >> N >> M >> X;
    for(int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        v[a].push_back({c, b});  // 비용, 정점
    }
}

// start로부터 다른 정점까지 가는 최단 거리를 구할 수 있다.
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
            if (d[v[node][i].second] < price +  v[node][i].first)
                continue;
            d[v[node][i].second] = price +  v[node][i].first;
            pq.push({d[v[node][i].second], v[node][i].second});
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    for(int i = 1; i <= N; i++)
    {
        get_dist(i);  // i부터 X까지의 최단 경로 찾기
        toX[i] = d[X];
    }
    get_dist(X);  // X부터 i까지의 최단 경로 찾기
    for(int i = 1; i <= N; i++)
    {
        toS[i] = d[i];
    }
    for(int i = 1; i <= N; i++)
    {
        ans = max(ans, toX[i] + toS[i]);
    }
    cout << ans;
    return (0);
}