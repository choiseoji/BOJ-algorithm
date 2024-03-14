#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;
int res;
vector<int> v;

void input(void)
{
    cin >> N >> C;
    for(int i = 0; i < N; i++)
    {
        int num;

        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
}

void solve(void)
{
    int l, r, m;     // 이게 다 거리를 나타내는 거임

    l = 0;
    r = v[v.size() - 1];

    while (l <= r)
    {
        m = (l + r) / 2;   // m 을 집 간 최대 거리라고 생각
        int cnt = 1;
        int idx = 0;

        for(int i = 0; i < N; i++)
        {
            if (abs(v[i] - v[idx]) >= m)
            {
                idx = i;
                cnt++;
            }
        }

        if (cnt >= C)
        {
            res = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();
    cout << res;
    return (0);
}