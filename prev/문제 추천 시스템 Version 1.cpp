/**
 * 자료구조, 트리를 사용한 집합과 맵, 우선순위 큐, 이진 검색 트리
*/
#include <iostream>
#include <set>
#include <map>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    int n;
    int P, L;  // 문제 번호, 난이도
    string cmd;
    set<pair<int, int>> s;   // 난이도, 문제 번호
    map<int, int> m;

    cin >> N;
    while (N--)
    {
        cin >> P >> L;
        s.insert({L, P});
        m[P] = L;
    }
    cin >> M;
    while (M--)
    {
        cin >> cmd;
        if (cmd == "add")
        {
            cin >> P >> L;
            s.insert({L, P});
            m[P] = L;
        }
        else if (cmd == "solved")
        {
            cin >> P;
            s.erase({m[P], P});
        }
        else if (cmd == "recommend")
        {
            cin >> n;
            if (n == 1)  // 가장 어려운 문제
            {
                cout << (*prev(s.end())).second << "\n";
            }
            else if (n == -1)  // 가장 쉬운 문제
            {
                cout << (*s.begin()).second << "\n";
            }
        }
    }
    return (0);
}