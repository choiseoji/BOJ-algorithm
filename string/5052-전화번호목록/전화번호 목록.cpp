#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t, n;
string str;
vector<string> v;

void init(void)
{
    int s;

    s = v.size();
    for(int i = 0; i < s; i++)
    {
        v.pop_back();
    }
}

void check(void)
{
    int length;

    sort(v.begin(), v.end());  // 문자열 리스트 정렬
    // 접두어만 비교
    for(int i = 0; i < v.size() - 1; i++)
    {
        length = v[i].size();
        if (v[i + 1].size() < length)
            continue;
        for(int j = 0; j < length; j++)
        {
            if (v[i][j] != v[i + 1][j])
                break;
            if (j == length - 1)
            {
                cout << "NO\n";
                return ;
            }
        }
    }
    cout << "YES\n";
    return ;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        for(int j = 0; j < n; j++)
        {
            cin >> str;
            v.push_back(str);
        }
        check();
        init();
    }
    return (0);
}
