#include <iostream>
using namespace std;

int main(void)
{
    int flag = 0;
    string str, find;

    cin >> str >> find;
    for(int i = 0; i < str.size(); i++)
    {
        if (str[i] == find[0])  // 찾으려는 문자열과 첫 글자가 같으면
        {
            int s = 0;
            for(int j = 0; j < find.size(); j++)
            {
                if (str[i + j] != find[j])  // 하나라도 틀리면 break
                    break ;
                s++;
            }
            if (s == find.size())
            {
                flag = 1;
                break ;
            }
        }
    }
    cout << flag;
    return (0);
}