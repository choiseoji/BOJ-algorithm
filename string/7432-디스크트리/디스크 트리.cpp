#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int 	N;
string	path;
vector<vector<string>> v;
vector<string> cmp;
vector<pair<string, int>> ans;  // 문자열, 깊이

void input(void)
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> path;

		string			buff;
		istringstream	s(path);  // istringstream 변수에 path 넣어서 초기화
		vector<string>	n;
		while (getline(s, buff, '\\'))  // \ 특수문자라서...
		{
			n.push_back(buff);
		}
		v.push_back(n);
	}
}

void solve(void)
{
	for(int i = 0; i < v[0].size(); i++)
	{
		ans.push_back({v[0][i], i});
		cmp.push_back({v[0][i]});
	}

	for(int i = 1; i < v.size(); i++)
	{
		for(int j = 0; j < v[i].size(); j++)
		{
			if (cmp.size() > j)
			{
				if (cmp[j] != v[i][j])
				{
					cmp.erase(cmp.begin() + j, cmp.end());
                    cmp.push_back(v[i][j]);
                    ans.push_back({v[i][j], j});
				}
			}
			else
			{
				cmp.push_back(v[i][j]);
                ans.push_back({v[i][j], j});
			}
		}
	}
}

void output(void)
{
	for(int i = 0; i < ans.size(); i++)
	{
		for(int j = 0; j < ans[i].second; j++)
		{
			cout << " ";
		}
		cout << ans[i].first << "\n";
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	// 입력받은 벡터 정렬
	sort(v.begin(), v.end());
	solve();
	output();
	return (0);
}

// GAMES
// GAMES\DRIVERS
// HOME
// WIN\SOFT
// WINNT\SYSTEM32\CERTSRV\CERTCO~1\X86
// WINNT\SYSTEM32\CONFIG
