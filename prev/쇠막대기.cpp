#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int ans = 0;
    string str;
    stack<char> st;

    cin >> str;
    for(int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            st.push(str[i]);
        }
        else
        {
            st.pop();
            // 바로 앞에 '(' 이면 레이저라서 스택에 있는 막대기만큼
            if (str[i - 1] == '(')
                ans += st.size();
            else  // 아니면 막대기의 끝이라는 의미 -> 조각 하나만 생김
                ans++;
        }
    }
    cout << ans;
    return (0);
}
