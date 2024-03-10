#include <iostream>
#include <vector>
using namespace std;

int N, num;
int value, ans1, ans2, tmp;
vector<int> v;

void input(void)
{
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> num;
        v.push_back(num);
    }
}

void solve(void)
{
    int s = 0;
    int e = N - 1;
    tmp = abs(v[s] + v[e]);
    ans1 = v[s];
    ans2 = v[e];

    while (s < e)
    {
        value = v[s] + v[e];

        if (tmp > abs(value))
        {
            tmp = abs(value);
            ans1 = v[s];
            ans2 = v[e];
        }
        if (value == 0)   // 더 볼 필요가 없음
            break ;

        if (value > 0)
            e--;
        else
            s++;
    }
    cout << ans1 << " " << ans2;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();
    return (0);
}