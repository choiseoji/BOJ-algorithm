#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int ans = 0;
    int N, num;
    priority_queue<int, vector<int>, greater<int>> q;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        q.push(num);
    }
    while (q.size() > 1)
    {
        int a = q.top(); q.pop();
        int b = q.top(); q.pop();
        ans += (a + b);
        q.push(a + b);
    }
    cout << ans;
    return (0);
}