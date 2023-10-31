#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int s;
	int tmp = 1;
	int ans = 0;
	string str;
	stack<char> st;

	cin >> str;
	s = str.length();
	for(int i = 0; i < s; i++)
	{
		if (str[i] == '(')
		{
			st.push(str[i]);
			tmp *= 2;
		}
		else if (str[i] == ')')
		{
			if (st.empty() || st.top() != '(')
			{
				ans = 0;
				break ;
			}
			else if (str[i - 1] == '(')
			{
				ans += tmp;
				tmp /= 2;
				st.pop();
			}
			else
			{
				tmp /= 2;
				st.pop();
			}
		}
		else if (str[i] == '[')
		{
			st.push(str[i]);
			tmp *= 3;
		}
		else if (str[i] == ']')
		{
			if (st.empty() || st.top() != '[')
			{
				ans = 0;
				break ;
			}
			else if (str[i - 1] == '[')
			{
				ans += tmp;
				tmp /= 3;
				st.pop();
			}
			else
			{
				tmp /= 3;
				st.pop();
			}
		}
	}
	if (!st.empty())
		ans = 0;
	cout << ans;
	return (0);
}