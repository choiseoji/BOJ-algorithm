#include <iostream>
#include <queue>
using namespace std;

int N, day;
long long ans;
int dead_line, price;
// 이제 큐의 top에는 가장 작은 값이 들어가 있을 것임.
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<int, vector<int>, greater<int>> pr;

void input(void)
{
    cin >> N;
    while (N--)
    {
        cin >> dead_line >> price;
        pq.push({dead_line, price});
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    day = 1;
    while (!pq.empty())
    {
        int cur_day;
        int cur_price;

        cur_day = pq.top().first;
        cur_price = pq.top().second;
        pq.pop();
        if (day <= cur_day)
        {
            pr.push(cur_price);   //  데드라인이 안지났다면 pr에 넣어주기
            day++;
        }
        else
        {
            // 만약 데드라인이 지났다면 바로 전 price와 현재를 비교해서 현재가 더 크면 
            // 바로 전 price대신 현재 price를 넣어줌 (전과제를 할 시간에 현재꺼를 하겠다!)
            if (pr.top() < cur_price)
            {
                pr.pop();
                pr.push(cur_price);
            }
        }
    }
    while (!pr.empty())
    {
        ans += pr.top();
        pr.pop();
    }
    cout << ans;
    return (0);
}
