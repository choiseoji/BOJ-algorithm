#include <iostream>
using namespace std;

int ans = -1;
int paper[5];
int board[10][10];

void input(void)
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cin >> board[i][j];
        }
    }
}

void fill_zero_or_one(int i, int j, int k, int num)
{
    for(int y = i; y <= i + k; y++)
    {
        for(int x = j; x <= j + k; x++)
        {
            board[y][x] = num;
        }
    }
}

int is_done(void)
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if (board[i][j] != 0)
                return (0);
        }
    }
    return (1);
}

int check_range(int i, int j, int k)
{
    if (i + k >= 10 || j + k >= 10)
        return (0);
    for(int y = i; y <= i + k; y++)
    {
        for(int x = j; x <= j + k; x++)
        {
            if (board[y][x] != 1)
                return (0);
        }
    }
    return (1);
}

void solve(int cnt)
{
    if (ans != -1 && cnt > ans)
        return ;
    if (is_done())  // 다 0 이면 최솟값 갱신
    {
        ans = cnt;
        return ;
    }
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if (board[i][j] == 1)
            {
                for(int k = 0; k < 5; k++)
                {
                    if (paper[k] < 5 && check_range(i, j, k))
                    {
                        paper[k]++;
                        fill_zero_or_one(i, j, k, 0);  // 0 으로 채우기
                        solve(cnt + 1);
                        fill_zero_or_one(i, j, k, 1);  // 다시 1로 다시 돌리기
                        paper[k]--;
                    }
                }
                return ;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve(0);
    cout << ans;
    return (0);
}