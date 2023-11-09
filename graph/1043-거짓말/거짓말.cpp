#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N, M;
int t, n;
int flag, cnt, ans;
vector<int> meet[51];
map<int, int> m;
int visited[51];   // 이미 거짓말을 할 수 없는 파티는 표시해둔다.

void input(void)
{
    cin >> N >> M;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        m[n] = 1;
    }
    for(int i = 0; i < M; i++)
    {
        cin >> t;
        for(int j = 0; j < t; j++)
        {
            cin >> n;

            meet[i].push_back(n);   // 각 파티의 멤버 저장
        }
    }
}

void check_party(void)
{
    while (1)
    {
        cnt = 0;
        for(int i = 0; i < M; i++)
        {
            cnt++;
            if (visited[i])   // 이미 거짓말을 할 수 없는 파티는 볼 필요 없음.
                continue;
            for(int j = 0; j < meet[i].size(); j++)
            {
                if (m[meet[i][j]] == 1)  // 진실을 아는 사람이 한명이라도 있으면 그 파티 인원 다 체크해두기
                {
                    for(int j = 0; j < meet[i].size(); j++)
                    {
                        m[meet[i][j]] = 1;
                    }
                    visited[i] = true;
                    cnt--;
                    break ;
                }
            }
        }
        if (cnt == M)
            break;
    }
}

void output(void)
{
    // 거짓말 할 수 있는 파티 수 cnt 해주기
    for(int i = 0; i < M; i++)
    {
        cnt = 0;
        for(int j = 0; j < meet[i].size(); j++)
        {
            if (m[meet[i][j]] == 1)
                break;
            cnt++;
        }
        if (cnt == meet[i].size())
            ans++;
    }
    cout << ans;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    check_party();
    output();
    return (0);
}
