#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, K;  // 도시의 수, 도로의 수, 면접장의 수
vector<pair<long long, int>> adj[100001];  // 비용, 정점 번호
vector<int> p;
long long d[100001];
long long ans_node, ans_price;

void input(void)
{
	cin >> N >> M >> K;
	for(int i = 0; i < M; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;
		adj[b].push_back({c, a});  // 역방향으로 입력받기
	}
	// 면접장 위치
	for(int i = 0; i < K; i++)
	{
		int place;

		cin >> place;
		p.push_back(place);
	}
}

void get_dist(void)
{
	fill(d, d + N + 1, 1e18);
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

	for(int i = 0; i < K; i++)
	{
		d[p[i]] = 0;
		pq.push({d[p[i]], p[i]});
	}
	while (!pq.empty())
	{
		int node = pq.top().second;
		long long price = pq.top().first;
		pq.pop();

		if (d[node] != price)
			continue;

		for(int i = 0; i < adj[node].size(); i++)
		{
			if (d[adj[node][i].second] <= d[node] + adj[node][i].first)
				continue;
			d[adj[node][i].second] = d[node] + adj[node][i].first;
			pq.push({d[adj[node][i].second], adj[node][i].second});
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	get_dist();
	for(int i = 1; i <= N; i++)
	{
		if (ans_price < d[i])
		{
			ans_price = d[i];
			ans_node = i;
		}
	}
	cout << ans_node << "\n" << ans_price << "\n";
	return (0);
}
