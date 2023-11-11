#include <iostream>
#include <vector>
using namespace std;

int w, h;
int ans;
int board[21][21];
vector<pair<int, int>> dirt_place;  // 인덱스가 더러운 지점의 번호가 됨
vector<pair<int, int>> dist;   // first: 더러운 지점, second: 그 지점까지의 거리
int visited[500];

void init(void)
{
    ans = 0;
    memset(visited, 0, sizeof(visited));
    memset(board, 0, sizeof(board));
    dirt_place.clear();
    dist.clear();
}

int input(void)
{
    cin >> w >> h;
    if (w == 0 && h == 0)
        return (1);
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == '*')
                dirt_place.push_back({i, j});   // 더러운 곳 위치 저장
        }
    }
    return (0);
}

void get_distance(void)
{
    for(int i = 0; i < dirt_place.size(); i++)
    {
        
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (1)
    {
        if (input())
            break;
        init();
        get_distance();

        cout << ans << "\n";
    }

    return (0);
}
