#include <iostream>
using namespace std;

int ans = 0;
int n, r, c;

void z(int x, int y, int size) // 시작점, 사이즈
{
    if (x == c && y == r)
    {
        cout << ans;
        return ;
    }

    if (c >= x && c < x + size && r >= y && r < y + size)
    {
        z(x, y, size / 2);
        z(x + size / 2, y, size / 2);
        z(x, y + size / 2, size / 2);
        z(x + size / 2, y + size / 2, size / 2);
    }
    else
        ans += size * size;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r >> c;
    z(0, 0, 1 << n);
    return (0);
}