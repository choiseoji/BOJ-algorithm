#include <iostream>
#include <stack>
#include <map>
using namespace std;

int     i;
string  str;
stack<char> st;
map<char, int> op;

void    get_rank(void)
{
    op['('] = 1;
    op[')'] = 1;
    op['*'] = 2;
    op['/'] = 2;
    op['+'] = 3;
    op['-'] = 3;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    get_rank();
    cin >> str;
    i = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            cout << str[i];
        else if (str[i] == ')')
        {
            while (st.top() != '(')
            {
                cout << st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            if (st.empty() || st.top() == '(' || (op[st.top()] > op[str[i]]))
            {
                st.push(str[i]);
            }
            else
            {
                while (!st.empty() && st.top() != '(' && (op[st.top()] <= op[str[i]]))
                {
                    cout << st.top();
                    st.pop();
                }
                st.push(str[i]);
            }
        }
        i++;
    }
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    return (0);
}
