#include <iostream>
#include <deque>
using namespace std;

int N, K;
int visited[100001];  //  visited[i] : i에 도달한 시간
deque<int> dq;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    dq.push_back(N);
    visited[N] = 1;
    while (!dq.empty())
    {
        int cur = dq.front();
        dq.pop_front();

        if (cur == K)
        {
            cout << visited[K] - 1;
            break ;
        }

        if ((2 * cur >= 0) && (2 * cur <= 100000))
        {
            if (!visited[2 * cur])
            {
                visited[2 * cur] = visited[cur];
                dq.push_front(2 * cur);
            }
        }
        if ((cur - 1 >= 0) && (cur - 1 <= 100000))
        {
            if (!visited[cur - 1])
            {
                visited[cur - 1] = visited[cur] + 1;
                dq.push_back(cur - 1);
            }
        }
        if ((cur + 1 >= 0) && (cur + 1 <= 100000))
        {
            if (!visited[cur + 1])
            {
                visited[cur + 1] = visited[cur] + 1;
                dq.push_back(cur + 1);
            }
        }
    }
    return (0);
}
