#include <iostream>
#include <set>
using namespace std;

int N, M;
int p, l, g, x;  // 문제 번호, 난이도, 알고리즘 
string cmd;
set<pair<int, int>> al[101];  // 알고리즘: 난이도, 문제번호
set<int> pr2[100001]; // 난이도: 문제번호
pair<int, int> pr[100001];  // 문제번호: 난이도, 알고리즘

void input(void)
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> p >> l >> g;
        al[g].insert({l, p});
        pr[p] = {l, g};
        pr2[l].insert(p);
    }
}

void add(void)
{
    cin >> p >> l >> g;
    al[g].insert({l, p});
    pr[p] = {l, g};
    pr2[l].insert(p);
}

void solved(void)
{
    int level;
    int group;

    cin >> p;
    level = pr[p].first;
    group = pr[p].second;
    al[group].erase({level, p});
    pr2[level].erase(p);
}

// 알고리즘 분류 g 중에
void recommend(void)
{
    cin >> g >> x;
    if (x == 1)  // 가장 어려운 문제
    {
        if (al[g].empty())
            return ;
        cout << (*prev(al[g].end())).second << "\n";
    }
    else
    {
        if (al[g].empty())
            return ;
        cout << (*al[g].begin()).second << "\n";
    }
}

void recommend2(void)
{
    cin >> x;
    if (x == 1)  // 가장 어려운 문제
    {
        for(int i = 100; i >= 1; i--)
        {
            if (pr2[i].empty())
                continue;
            cout << *prev(pr2[i].end()) << "\n";
            break ;
        }
    }
    else if (x == -1)
    {
        for(int i = 1; i <= 100; i++)
        {
            if (pr2[i].empty())
                continue;
            cout << *pr2[i].begin() << "\n";
            break ;
        }
    }
}

// 난이도 범위가 정해져있음
void recommend3(void)
{
    cin >> l >> x;
    if (x == 1)  // 가장 쉬운 문제
    {
        for(int i = l; i <= 100; i++)
        {
            if (pr2[i].empty())
                continue;
            cout << *pr2[i].begin() << "\n";
            break ;
        }
    }
    else if (x == -1)
    {
        for(int i = l - 1; i >= 1; i--)
        {
            if (pr2[i].empty())
                continue;
            cout << *prev(pr2[i].end()) << "\n";
            break ;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        cin >> cmd;
        if (cmd == "add")
            add();
        else if (cmd == "solved")
            solved();
        else if (cmd == "recommend")
            recommend();
        else if (cmd == "recommend2")
            recommend2();
        else if (cmd == "recommend3")
            recommend3();
    }
    return (0);
}