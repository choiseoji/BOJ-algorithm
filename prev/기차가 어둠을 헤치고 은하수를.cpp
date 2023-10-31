#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N, M;  // 기차의 수, 명령의 수
int cnt = 0;
vector<int> train(100001);
map<int, bool> visited;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    while (M--)
    {
        int n, i, x;

        cin >> n >> i;
        if (n == 1)  // 승차
        {
            cin >> x;
            train[i] |= (1 << x);
        }
        else if (n == 2)  // 하차
        {
            cin >> x;
            train[i] &= ~(1 << x);
        }
        else if (n == 3)  // 오른쪽으로 이동
        {
            train[i] = train[i] << 1;
            train[i] &= ((1 << 21) - 1);   // 마지막 친구 내려주기
        }
        else if (n == 4)  // 왼쪽으로 이동
        {
            train[i] = train[i] >> 1;
            train[i] &= ~1;   // 첫번째 친구 내려주기
        }
    }

    for(int i = 1; i <= N; i++)
    {
        if (!visited[train[i]])
        {
            visited[train[i]] = true;
            cnt++;
        }
    }
    cout << cnt;
    return (0);
}