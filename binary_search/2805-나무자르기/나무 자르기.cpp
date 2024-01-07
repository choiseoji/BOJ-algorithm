#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;    // 나무의 수, 가져가려는 최소 나무 길이
int ans;
vector<int> tree;

long long cut_tree(int m)
{
	long long	size = 0;

	for(int i = 0; i < N; i++)
	{
		if (tree[i] > m)
			size += (tree[i] - m);
	}
	return (size);
}

int solve(void)
{
	long long r, l, m, size;

	r = tree[N - 1];
	l = 0;
	while (l <= r)
	{
		m = (r + l) / 2;
		size = cut_tree(m);
		if (size < M)
			r = m - 1;
		else if (size >= M)
        {
            ans = m;
            l = m + 1;
        }
	}
	return (ans);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		int num;

		cin >> num;
		tree.push_back(num);
	}
	sort(tree.begin(), tree.end());
	cout << solve();
	return (0);
}
