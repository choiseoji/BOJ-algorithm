#include <iostream>
#include <vector>
using namespace std;

int N, M, D;  // D : 공격 거리 제한
int map[15][15];
vector<pair<pair<int, int>, int>> v;

void input(void)
{
    cin >> N >> M >> D;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }
}

int check_is_end(void)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if (map[i][j] == 1)
                return (1);
        }
    }
    return (0);
}

void get_three_place(void)
{

}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    get_three_place();
    while (!check_is_end())
    {

    }
    return (0);
}
