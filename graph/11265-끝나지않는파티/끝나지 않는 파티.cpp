#include <iostream>
using namespace std;

int N, M;
int map[505][505];

void input(void)
{
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> map[i][j];   // 파티장 정보
        }
    }
}

void solve(void)
{
    for(int k = 1; k <= N; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
}

void output(void)
{
    int idx1, idx2, t;
    while (M--)
    {
        cin >> idx1 >> idx2 >> t;
        if (map[idx1][idx2] <= t)
            cout << "Enjoy other party\n";
        else
            cout << "Stay here\n";
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();
    output();
    return (0);
}