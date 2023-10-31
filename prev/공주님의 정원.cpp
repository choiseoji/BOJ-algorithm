#include <iostream>
#include <algorithm>
using namespace std;

typedef struct s_flower {
    int end_day;
    int start_day;
}   t_flower;

int N, cnt;
t_flower flower[100001];

void input(void)
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int sm, sd, em, ed;

        cin >> sm >> sd >> em >> ed;
        flower[i].start_day = sm * 100 + sd;
        flower[i].end_day = em * 100 + ed;
    }
}

bool cmp1(t_flower f1, t_flower f2)
{
    if (f1.start_day == f2.start_day)
        return f1.end_day < f2.end_day;
    return f1.start_day < f2.start_day;
}

bool cmp2(t_flower f1, t_flower f2)
{
    return f1.end_day > f2.end_day;
}

int invalid_input(void)
{
    // 늦게 지는 순서로 정렬
    sort(flower, flower + N, cmp2);
    if (flower[0].end_day < 1130)
        return (1);
    // 빨리 피는 순서로 정렬
    sort(flower, flower + N, cmp1);
    if (flower[0].start_day > 301)
        return (1);
    return (0);
}

int solve(void)
{
    // 3월 1일 이전에 피는데, 제일 늦게 지는 꽃 찾기
    int i, idx, m, cur;  // idx : 현재 피어있는 꽃의 인덱스, cur : 현재 꽃의 지는 날짜

    i = 0;
    m = -1;
    while (flower[i].start_day <= 301)
    {
        if (flower[i].end_day > m)
        {
            m = flower[i].end_day;
            idx = i;  // 조건에 만족하고, 제일 늦게 피는 꽃의 인덱스 저장
        }
        i++;
    }
    m = -1;
    cnt = 1;
    cur = flower[idx].end_day;  // 지는 날짜
    // 현재 꽃이 지기 전에 피고, 그 중 제일 늦게 지는 꽃 찾기, 11월 30일 넘어가면 break (while 문에서)
    while (flower[idx].end_day <= 1130)
    {
        int tmp = idx;
        for(int i = idx + 1; i < N; i++)
        {
            if (flower[i].start_day <= cur)  // 현재 꽃 지기 전에 피는 꽃 중에
            {
                if (flower[i].end_day >= m)
                {
                    m = flower[i].end_day;
                    idx = i;
                }
            }
        }

        if (idx == tmp)  // 현재 꽃 갱신이 안된 경우 -> 현재 꽃이 지기 전에 피는 꽃이 없음
        {
            cout << 0;
            return (0);
        }
        else
        {
            cnt++;
            cur = flower[idx].end_day;
        }
    }
    cout << cnt;
    return (0);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    if (invalid_input())
        cout << 0;
    else
        solve();
    return (0);
}