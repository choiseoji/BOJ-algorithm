#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int res;
vector<int> snack;

void input(void)
{
    cin >> M >> N;
    for(int i = 0; i < N; i++)
    {
        int num;

        cin >> num;
        snack.push_back(num);
    }
    sort(snack.begin(), snack.end());
}

int check(int m)
{
    int cnt = 0;

    for(int i = 0; i < snack.size(); i++)
    {
        cnt += (snack[i] / m);
    }
    return (cnt);
}

void solve(void)
{
    int l, r, m;
    int cnt;

    l = 1;
    r = snack[N - 1];

    while (l <= r)
    {
        m = (l + r) / 2;

        cnt = check(m);

        if (cnt >= M)
        {
            res = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    cout << res;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();
    return (0);
}