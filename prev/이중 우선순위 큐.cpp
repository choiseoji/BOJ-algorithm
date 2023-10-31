#include <iostream>
#include <set>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, k;

    cin >> t;
    while (t--)
    {
        cin >> k;
        multiset<int> ms;
        while (k--)
        {
            char c;
            int num;

            cin >> c >> num;
            if (c == 'I')
                ms.insert(num);
            else if (c == 'D')
            {
                if (ms.empty())
                    continue;
                if (num == 1)  // 최댓값 찾기
                    ms.erase(prev(ms.end()));
                else if (num == -1)  // 최솟값 찾기
                    ms.erase(ms.begin());
            }
        }
        if (ms.empty())
            cout << "EMPTY\n";
        else
            cout << *prev(ms.end()) << " " << *ms.begin() << "\n";
    }
    return (0);
}