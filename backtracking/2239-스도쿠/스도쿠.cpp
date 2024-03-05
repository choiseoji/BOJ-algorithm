#include <iostream>
#include <vector>
using namespace std;

int board[10][10];
vector<pair<int ,int>> loc;

void input(void)
{
    string str;

    for(int i = 0; i < 9; i++)
    {
        cin >> str;
        for(int j = 0; j < 9; j++)
        {
            board[i + 1][j + 1] = str[j] - '0';
            if (board[i + 1][j + 1] == 0)
                loc.push_back({i + 1, j + 1});
        }
    }
}

void output(void)
{
    for(int i = 1; i < 10; i++)
    {
        for(int j = 1; j < 10; j++)
        {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

bool check_board(int x, int y)
{
    int num = board[y][x];

    // 가로줄 체크
    for(int i = 1; i < 10; i++)
    {
        if (i != x && num == board[y][i])
            return (false);
    }
    // 세로줄 체크
    for(int i = 1; i < 10; i++)
    {
        if (i != y && num == board[i][x])
            return (false);
    }
    // 정사각형 체크
    int start_y = 3 * ((y - 1) / 3) + 1;
    int start_x = 3 * ((x - 1) / 3) + 1;
    for(int i = start_x; i < start_x + 3; i++)
    {
        for(int j = start_y; j < start_y + 3; j++)
        {
            if (i != x && j != y && num == board[j][i])
                return (false);
        }
    }
    return (true);
}

void solve(int idx)
{
    if (idx == loc.size())
    {
        output();
        exit(0);
    }

    int x = loc[idx].second;
    int y = loc[idx].first;

    for(int i = 1; i < 10; i++)
    {
        board[y][x] = i;
        if (check_board(x, y))
            solve(idx + 1);
        board[y][x] = 0;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve(0);
    return (0);
}