#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, T;
    int ans = -1;
    int d[301][301];

    cin >> N >> M >> T;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = 0x3f3f3f3f;
        }
    }
    while (M--)
    {
        int u, v, h;

        cin >> u >> v >> h;
        d[u][v] = h;
    }
    for(int k = 1; k <= N; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
            }
        }
    }
    // answer
    while (T--)
    {
        int u, v;

        cin >> u >> v;
        if (d[u][v] != 0x3f3f3f3f)
            cout << d[u][v] << "\n";
        else
            cout << -1 << "\n";
    }
    return (0);
}
