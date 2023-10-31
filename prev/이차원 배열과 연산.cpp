#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int idx;
int r, c, k;
int R, C;
int board[101][101];
int num_cnt[101];

void input(void)
{
	cin >> r >> c >> k;
	for(int i = 1; i <= 3; i++)
	{
		for(int j = 1; j <= 3; j++)
		{
			cin >> board[i][j];
		}
	}
	R = 3;
	C = 3;
}

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

void solve(void)
{
	int time = 0;

	while (1)
	{
		if(board[r][c] == k)
		{
			cout << time;
			break ;
		}
		if (time > 100)
		{
			cout << -1;
			break ;
		}

		if (R >= C)
		{
			int c_size = -1;

			for(int i = 1; i <= R; i++)
			{
				vector<pair<int, int>> v;
				memset(num_cnt, 0, sizeof(num_cnt));
				for(int j = 1; j <= C; j++)
				{
					num_cnt[board[i][j]] ++;
				}
				for(int j = 1; j <= 100; j++)
				{
					if (num_cnt[j])
						v.push_back({num_cnt[j], j});  //첫번째 원소가 횟수
				}
				sort(v.begin(), v.end(), compare);  // 횟수 기준 정렬
				for(int j = 1; j <= 100; j++)
				{
					board[i][j] = 0;
				}
				idx = 1;
				for(int j = 0; j < v.size(); j++)
				{
					board[i][idx++] = v[j].second;
					board[i][idx++] = v[j].first;
				}
				c_size = max(c_size, (int)v.size() * 2);
				C = c_size;
			}
		}
		else
		{
			int r_size = -1;

			for(int j = 1; j <= C; j++)
			{
				vector<pair<int, int>> v;
				memset(num_cnt, 0, sizeof(num_cnt));
				for(int i = 1; i <= R; i++)
				{
					num_cnt[board[i][j]]++;
				}
				for(int i = 1; i <= 100; i++)
				{
					if (num_cnt[i])
						v.push_back({num_cnt[i], i});
				}
				sort(v.begin(), v.end(), compare);
				for(int i = 1; i <= 100; i++)
				{
					board[i][j] = 0;
				}
				idx = 1;
				for(int i = 0; i < v.size(); i++)
				{
					board[idx++][j] = v[i].second;
					board[idx++][j] = v[i].first;
				}
				r_size = max(r_size, (int)v.size() * 2);
				R = r_size;
			}
		}
		time++;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	solve();
	return (0);
}