#include <iostream>
#include <vector>
using namespace std;

int N, M, T;
int x, d, k;
vector<int> n[52];
vector<int> c[52];

void input(void)
{
    cin >> N >> M >> T;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            int num;

            cin >> num;
            n[i].push_back(num);
        }
    }
}

int get_sum(int *div)
{
    int cnt = 0;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if (n[i][j] != 0)
            {
                cnt += n[i][j];
                (*div)++;
            }
        }
    }
    return (cnt);
}

void rotate_table(int idx)
{
    int tmp;

    for(int i = 0; i < k; i++)
    {
        if (d == 0)  // 시계방향
        {
            tmp = n[idx][M - 1];
            for(int k = M - 1; k > 0; k--)
            {
                n[idx][k] = n[idx][k - 1];
            }
            n[idx][0] = tmp;
        }
        else if (d == 1)  // 반시계방향
        {
            tmp = n[idx][0];
            for(int k = 0; k < M - 1; k++)
            {
                n[idx][k] = n[idx][k + 1];
            }
            n[idx][M - 1] = tmp;
        }
    }
}

void copy_table(void)
{
    // 일단 c init
    for(int i = 1; i <= N; i++)
    {
        c[i].clear();
    }
    // c 복사
    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            c[i].push_back(n[i][j]);
        }
    }
}

// 인접한 수 지우기
void delete_num(void)
{
    int flag = 0;

    copy_table();
    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            // 다른 원과 비교
            if (i != N && c[i][j] != 0 &&  c[i][j] == c[i + 1][j])
            {
                flag = 1;
                n[i][j] = 0;
                n[i + 1][j] = 0;
            }
            // 같은 원에서 비교
            if (c[i][j] != 0 && c[i][j] == c[i][(j + 1) % M])
            {
                flag = 1;
                n[i][j] = 0;
                n[i][(j + 1) % M] = 0;
            }
        }
    }

    if (flag == 0)  // 인접한 칸에 같은 수가 없던 경우
    {
        int sum, div;
        double av;

        div = 0;
        sum = get_sum(&div);
        av = (double) sum / div;
        // cout << sum << " " << div << " " << av << "\n";
        for(int i = 1; i <= N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if (n[i][j] != 0 && (double)n[i][j] > av)
                    n[i][j] -= 1;
                else if (n[i][j] != 0 && (double)n[i][j] < av)
                    n[i][j] += 1;
            }
        }
    }
}

// void check_output()
// {
//     cout << "------------\n\n";
//     for(int i = 1; i <= N; i++)
//     {
//         for(int j = 0; j < M; j++)
//         {
//             cout << n[i][j] << " ";
//         }
//         cout << "\n";
//     }
//     cout << "\n\n";
// }

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tmp = 0;

    input();
    while (T--)
    {
        cin >> x >> d >> k;
        for(int i = 1; i <= N; i++)
        {
            if (i % x == 0)
                rotate_table(i);
        }
        delete_num();
    }
    cout << get_sum(&tmp);
    return (0);
}
