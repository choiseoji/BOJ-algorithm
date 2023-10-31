#include<iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

int flag = 0;
int N, K, L;
int cur = 0;
int nx = 1;
int ny = 0;
int t;
char d;
int map[102][102];  // 0: 빈칸, 1: 뱀, 2: 사과
queue<pair<int, int>> q;
deque<pair<int, int>> snake;

void set_dir(char d)
{
	if (d == 'L')
	{
		if (nx == 0 && ny == 1)
		{
			nx = 1;
			ny = 0;
		}
		else if (nx == 0 && ny == -1)
		{
			nx = -1;
			ny = 0;
		}
		else if (nx == 1 && ny == 0)
		{
			nx = 0;
			ny = -1;
		}
		else if (nx == -1 && ny == 0)
		{
			nx = 0;
			ny = 1;
		}
	}
	else if (d == 'D')
	{
		if (nx == 0 && ny == 1)
		{
			nx = -1;
			ny = 0;
		}
		else if (nx == 0 && ny == -1)
		{
			nx = 1;
			ny = 0;
		}
		else if (nx == 1 && ny == 0)
		{
			nx = 0;
			ny = 1;
		}
		else if (nx == -1 && ny == 0)
		{
			nx = 0;
			ny = -1;
		}
	}
}

void solve(int time, int nx, int ny)
{
	while (!q.empty())
	{
		if (cur == time)
			break ;
		
		int x = q.front().second + nx;
		int y = q.front().first + ny;
		q.pop();

		if (!(x > 0 && x <= N && y > 0 && y <= N) || map[y][x] == 1)
		{
			flag = 1;
			break ;
		}
		if (x > 0 && x <= N && y > 0 && y <= N)
		{
			if (map[y][x] == 0) // 사과가 없다면
			{
				int d_x = snake.front().second;
				int d_y = snake.front().first;
				snake.pop_front();
				map[d_y][d_x] = 0;
			}
			cur++;
			map[y][x] = 1;
			q.push({y, x});
			snake.push_back({y, x});
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	for(int i = 0; i < K; i++)
	{
		int x, y;

		cin >> y >> x;
		map[y][x] = 2;
	}
	cin >> L;
	map[1][1] = 1;
	q.push({1, 1});
	snake.push_back({1, 1});
	for(int i = 0; i < L; i++)
	{
		cin >> t >> d;
		if (flag == 0)
		{
			solve(t, nx, ny);
			set_dir(d);
		}
	}
	if (flag == 0)
	{
		solve(-1, nx, ny);
		set_dir(d);
	}
	cout << cur + 1;
	return (0);
}