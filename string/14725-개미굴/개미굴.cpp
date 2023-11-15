#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;
string str;
vector<vector<string>> v;
vector<pair<int, string>> ans;  // 깊이, 문자열
vector<string> cmp;  // 비교할 바로 전 문자열 벡터

void input(void)
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> K;
        vector<string> n;
        for(int j = 0; j < K; j++)
        {
            cin >> str;
            n.push_back(str);
        }
        v.push_back(n);
    }
}

void output(void)
{
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].first; j++)
        {
            cout << "--";
        }
        cout << ans[i].second << "\n";
    }
}

void solve(void)
{
    // 일단 첫번째 문자열 cmp랑 ans에 삽입
    for(int i = 0; i < v[0].size(); i++)
    {
        cmp.push_back(v[0][i]);
        ans.push_back({i, v[0][i]});
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
                    ans.push_back({j, v[i][j]});
                }
            }
            else
            {
                cmp.push_back(v[i][j]);
                ans.push_back({j, v[i][j]});
            }
        }
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
