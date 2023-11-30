#include <iostream>
#include <queue>
using namespace std;

int N;
int ans, eat_cnt;
int my_size = 2;
int sh_x, sh_y;
int map[22][22];
int visited[22][22];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pair<int, int>> q;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void input(void)
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 9)
            {
                map[i][j] = 0;
                sh_x = j;
                sh_y = i;
            }
        }
    }
}

void init(void)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            visited[i][j] = -1;
        }
    }
    while (!pq.empty())
        pq.pop();
}

void find_fish(void)
{
    int min_dist = 0x3f3f3f3f;

    init();
    q.push({sh_y, sh_x});
    visited[sh_y][sh_x] = 0;
    while (!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N && visited[ny][nx] == -1)
            {
                // 아기 상어 크기가 칸을 그냥 지나가는 경우 (아기상어크기 == 물고기크기)
                if ((my_size == map[ny][nx]) || map[ny][nx] == 0)
                {
                    q.push({ny, nx});
                    visited[ny][nx] = visited[y][x] + 1;
                }
                // 아기 상어가 물고리를 먹는 경우 (아기상어크기 > 물고기크기)
                else if ((my_size > map[ny][nx]) && (visited[y][x] + 1 <= min_dist))
                {
                    pq.push({ny, nx});
                    q.push({ny, nx});
                    visited[ny][nx] = visited[y][x] + 1;
                    min_dist = visited[ny][nx];
                }
                else  // 아기상어가 칸을 못 지나가는 경우 (아기상어크기 < 물고기크기)
                    continue;
            }
        }
    }
}

// 물고기 먹고 map 다시 조정
int eat_fish(void)
{
    if (pq.empty())
        return (0);

    int eat_x = pq.top().second;
    int eat_y = pq.top().first;

    eat_cnt++;
    map[eat_y][eat_x] = 0;
    ans += visited[eat_y][eat_x];
    if (eat_cnt == my_size)
    {
        my_size++;
        eat_cnt = 0;
    }
    sh_x = eat_x;
    sh_y = eat_y;
    return (1);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    while (1)
    {
        find_fish();
        if (!eat_fish())
            break;
    }
    cout << ans;
    return (0);
}

// #include <iostream>
// #include <queue>
// using namespace std;

// int N;
// int eat_cnt;
// int sh_x, sh_y;
// int my_size = 2;
// int map[22][22];
// int dx[4] = {0, -1, 1, 0};
// int dy[4] = {-1, 0, 0, 1};
// queue<pair<int, int>> q;
// bool visited[22][22];

// void input(void)
// {
//     cin >> N;
//     for(int i = 0; i < N; i++)
//     {
//         for(int j = 0; j < N; j++)
//         {
//             cin >> map[i][j];
//             if (map[i][j] == 9)
//             {
//                 map[i][j] = 0;
//                 sh_x = j;
//                 sh_y = i;
//             }
//         }
//     }
// }

// void init(void)
// {
//     for(int i = 0; i < N; i++)
//     {
//         for(int j = 0; j < N; j++)
//         {
//             visited[i][j] = false;
//         }
//     }
//     while (!q.empty())
//     {
//         q.pop();
//     }
// }

// int find_fish(int *is_eat)
// {
//     int q_size;
//     int cnt = -1;

//     init();
//     q.push({sh_y, sh_x});
//     visited[sh_y][sh_x] = true;
//     while (!q.empty())
//     {
//         cnt++;
//         q_size = q.size();
//         while (q_size--)
//         {
//             int x = q.front().second;
//             int y = q.front().first;
//             q.pop();

//             if (map[y][x] != 0 && map[y][x] < my_size)
//             {
//                 *is_eat = 1;
//                 map[y][x] = 0;  // 물고기 먹음
//                 sh_y = y;
//                 sh_x = x;
//                 eat_cnt++;
//                 if (eat_cnt == my_size)
//                 {
//                     my_size++;
//                     eat_cnt = 0;
//                 }
//                 return (cnt);
//             }

//             for(int i = 0; i < 4; i++)
//             {
//                 int nx = x + dx[i];
//                 int ny = y + dy[i];

//                 if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[ny][nx])
//                 {
//                     if (map[ny][nx] > my_size)
//                         continue;
//                     q.push({ny, nx});
//                     visited[ny][nx] = true;
//                 }
//             }
//         }
//     }
//     if (*is_eat == 0)
//         return (0);
//     return (cnt);
// }

// void solve(void)
// {
//     int is_eat = 1;
//     int ans = 0;

//     while (is_eat)
//     {
//         // 잡아먹을 물고기 찾기
//         is_eat = 0;
//         ans += find_fish(&is_eat);
//     }
//     cout << ans;
// }

// int main(void)
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     input();
//     solve();
//     return (0);
// }