#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 0;
    int weight = 0;
    int n, w, l;
    queue<int> q1;
    queue<int> q2;

    cin >> n >> w >> l;
    for(int i = 0; i < n; i++)
    {
        int num; cin >> num;
        q1.push(num);
    }
    while (!q1.empty())  // 트럭이 다 지나갈 때까지
    {
        if (q2.size() == w)  // 다리 위가 꽉 차있으면
        {
            weight -= q2.front();  // 다리 위 첫번째 트럭 지나가고
            q2.pop();
        }
        if (weight + q1.front() <= l)  // 하중 견딜 수 있으면 다음 트럭 올려주고
        {
            weight += q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        else  // 하중 못 견디면 트럭 올려주지 말기 (무게 0으로 해줘서 )
        {
            q2.push(0);
        }
        t++;
    }
    cout << t + w;  // 마자막 트럭이 다리에 올라온 순간이 q1이 empty인 경우라서 시간에 다리 길이만큼 더해주기
    return (0);
}