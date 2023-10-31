#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, K;
int ans;
int success;
int board[41][41];
vector<pair<int, int>> s[101];
vector<pair<int, int>> st[101];

void input(void)
{
    cin >> N >> M >> K;
    for(int k = 0; k < K; k++)
    {
        int R, C;
        
        cin >> R >> C;
        s[k].push_back({R, C});
        for(int r = 0; r < R; r++)
        {
            for(int c = 0; c < C; c++)
            {
                int num;

                cin >> num;
                if (num == 1)
                    st[k].push_back({r, c});  // 스티커 부분의 좌표만 저장
            }
        }
    }
}

int check_space(int i, int j, int idx)
{
    for(int k = 0; k < st[idx].size(); k++)
    {
        int x, y;

        x = j + st[idx][k].second;
        y = i + st[idx][k].first;
        if (x < 0 || x >= M || y < 0 || y >= N)
            return (0);
        if (board[y][x] == 1)
            return (0);
    }
    return (1);
}

void add_sticker(int i, int j, int idx)
{
    for(int k = 0; k < st[idx].size(); k++)
    {
        int x, y;

        x = j + st[idx][k].second;
        y = i + st[idx][k].first;
        board[y][x] = 1;
        ans++;
    }
}

void check_board(int idx)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if (check_space(i, j, idx))  // i, j 좌표가 시작 위치
            {
                add_sticker(i, j, idx);
                success = 1;
                return ;
            }
        }
    }
}

void rotate_sticker(int idx)
{
    int tmp;
    int x_size = s[idx][0].second;
    int y_size = s[idx][0].first;

    for(int i = 0; i < 3; i++)  // 한번이 90도 회전
    {
        for(int j = 0; j < st[idx].size(); j++)
        {
            int x = st[idx][j].second;
            int y = st[idx][j].first;

            st[idx][j].second = (y_size - 1) - y;
            st[idx][j].first = x;
        }
        tmp = x_size;
        x_size = y_size;
        y_size = tmp;
        check_board(idx);  // 회전시킨 스티커로 다시 보드 확인
        if (success == 1)
            return ;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    for(int k = 0; k < K; k++)  // 스티커 하나씩 확인   
    {
        success = 0;
        check_board(k);
        if (!success)
            rotate_sticker(k);
    }
    cout << ans;
    return (0);
}