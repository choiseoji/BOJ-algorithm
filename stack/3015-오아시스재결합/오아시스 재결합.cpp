#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int ans = 0;
    stack<pair<int, int>> st;

    cin >> N;
    while (N--)
    {
        int num;

        cin >> num;
        while (!st.empty() && st.top().first < num)
        {
            ans += st.top().second;
            st.pop();
        }
        if (st.empty())
            st.push({num, 1});
        else
        {
            if (st.top().first == num)
            {
                int cnt = st.top().second;
                ans += cnt;
                st.pop();
                if (!st.empty())
                    ans += 1;
                st.push({num, cnt + 1});
            }
            else
            {
                ans += 1;
                st.push({num, 1});
            }
        }
    }
    cout << ans;
    return (0);
}