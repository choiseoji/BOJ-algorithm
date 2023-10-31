#include <iostream>
using namespace std;

int ans = 4;
int N, M, H;
int	map[35][15];

void input(void)
{
	cin >> N >> M >> H;  // N: x, H: y
	for(int i = 1; i <= M; i++)
	{
		int x, y;

		cin >> y >> x;
		map[y][x] = 1;  // 시작점이고 오른쪽으로 이동 가능
		map[y][x + 1] = -1;  // 끝점이고 왼쪽으로 이동 가능
	}
}

int	is_right(int i, int j)
{
	// 현재 사다리가 있거나
	if (map[j][i] != 0)
		return (0);
	// 인접한 곳에 사다리가 있는 경우
	if (map[j][i + 1] != 0)
		return (0); 
	return (1);
}

int	play(void)
{
	int cur;  // 변하는 x좌표

	for(int i = 1; i <= N; i++) // x좌표
	{
		cur = i;
		for(int j = 1; j <= H; j++)  // y좌표
			cur += map[j][cur];
		if (i != cur)
			return (0);
	}
	return (1);  // 사다리 게임 성공
}

void solve(int cnt, int idx)
{
	if (cnt > 3)
		return ;
	if (play())
	{
		ans = min(ans, cnt);
		return ;
	}

	for(int i = idx; i < N; i++)
	{
		for(int j = 1; j <= H; j++)
		{
			if (is_right(i, j))
			{
				map[j][i] = 1;
				map[j][i + 1] = -1;
				cnt++;
				solve(cnt, i);
				cnt--;
				map[j][i] = 0;
				map[j][i + 1] = 0;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	solve(0, 1);
	if (ans == 4)
		ans = -1;
	cout << ans;
	return (0);
}