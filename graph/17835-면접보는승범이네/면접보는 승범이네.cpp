#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct info
{
	int node;
	int price;
};

int N, M, K;  // 도시의 수, 도로의 수, 면접장의 수
vector<pair<int, int>> adj[100001];  // 비용, 정점 번호
vector<int> p;
int d[100001];
info dist[100001];
int ans_node, ans_price;

void input(void)
{
	cin >> N >> M >> K;
	for(int i = 0; i < M; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;
		adj[a].push_back({c, b});
	}
	// 면접장 위치
	for(int i = 0; i < K; i++)
	{
		int place;

		cin >> place;
		p.push_back(place);
	}
}

void get_dist(int st)
{
	fill(d, d + N + 1, 0x3f3f3f3f);
	priority_queue<pair<int, int>> pq;
	d[st] = 0;
	pq.push({d[st], st});
	while (!pq.empty())
	{
		int node = pq.top().second;
		int price = pq.top().first;
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
	for(int i = 1; i <= N; i++)
	{
		get_dist(i);
		for(int j = 0; j < K; j++)  // 가장 가까운 면접장 찾기
		{
			if (j == 0)
			{
				dist[i].node = p[j];
				dist[i].price = d[p[j]];
			}
			else
			{
				if (dist[i].price > d[p[j]])
				{
					dist[i].node = p[j];
					dist[i].price = d[p[j]];
				}
			}
		}
	}
	// 정답 출력
	for(int i = 1; i <= N; i++)
	{
		if (ans_price < dist[i].price)
		{
			ans_node = i;
			ans_price = dist[i].price;
		}
	}
	cout << ans_node << "\n" << ans_price;
	return (0);
}
