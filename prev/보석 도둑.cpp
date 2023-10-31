#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

long long ans;
int N, K;   // 보석, 가방
int m, v, c;   // 무게, 가격, 가방에 담을 수 있는 최대 무게
pair<int, int> jewel[300001];  // 가격, 무게
multiset<int> bag;  // 담을 수 있는 보석의 최대 무게

void input(void)
{
    cin >> N >> K;
    for(int i = 0; i < N; i++)
    {
        cin >> m >> v;
        jewel[i] = {v, m};
    }
    sort(jewel, jewel + N);   // 가격 기준으로 정렬
    for(int i = 0; i < K; i++)
    {
        cin >> c;
        bag.insert(c);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    for(int i = N - 1; i >= 0; i--)
    {
        int price = jewel[i].first;
        int weight = jewel[i].second;
        
        // 보석을 담을 수 있는 최대 무게가 weight 보다는 크지만 그 중 가장 작은 iter을 찾아야 한다.
        auto iter = bag.lower_bound(weight);
        if (iter == bag.end())
            continue;
        ans += price;
        bag.erase(iter);
    }
    cout << ans;
    return (0);
}