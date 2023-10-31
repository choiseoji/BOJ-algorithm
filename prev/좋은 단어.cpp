#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string  str;
    int cnt = 0;

    cin >> N;
    while (N--)
    {
        stack<char> st;

        cin >> str;
        for(int i = 0; i < str.size(); i++)
        {
            if (!st.empty() && st.top() == str[i])
                st.pop();
            else
                st.push(str[i]);
        }
        if (st.empty())
            cnt++;
    }
    cout << cnt;
    return (0);
}