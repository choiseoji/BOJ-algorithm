#include <iostream>
using namespace std;

int N;
int L[21];
int J[21];
int ans = 0;

void input(void)
{
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> L[i];
    for(int i = 0; i < N; i++)
        cin >> J[i];
}

void solve(int idx, int st, int joy)
{
    if (st <= 0)
        return ;
    if (idx == N)
    {
        ans = max(ans, joy);
        return ;
    }
    solve(idx + 1, st - L[idx], joy + J[idx]); // 인사한 경우
    solve(idx + 1, st, joy);  // 인사 안 한 경우
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve(0, 100, 0);
    cout << ans;
    return (0);
}