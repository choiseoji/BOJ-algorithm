#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
    string          str;
    vector<string>  v;

    cin >> str;
    while (1)
    {
        v.push_back(str);
        if (str.size() == 1)
            break ;
        str = str.substr(1);     // 앞에서부터 한 글자씩 잘라주기
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\n";
    }
    return (0);
}