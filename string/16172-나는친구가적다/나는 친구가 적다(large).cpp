#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s, f;
    string str;

    cin >> s >> f;
    for(int i = 0; i < s.size(); i++)
    {
        // 알파벳만 str에 저장
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            str += s[i];
    }
    // str에 f찾기
    if (str.find(f) == string::npos)  // 못 찾으면 쓰레기값 반환
        cout << 0;
    else
        cout << 1;
    return (0);
}