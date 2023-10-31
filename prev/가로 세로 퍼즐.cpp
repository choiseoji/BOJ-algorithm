#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> v;
vector<string> puzzle;
bool visited[6];

void input(void)
{
    string str;

    for(int i = 0; i < 6; i++)
    {
        cin >> str;
        v.push_back(str);
    }
    sort(v.begin(), v.end());
}

void print_ans(void)
{
    for(int i = 0; i < 3; i++)
    {
        cout << puzzle[i] << "\n";
    }
}

int is_right(void)
{
    int flag = 0;
    string str;
    bool visited2[3] = {false, };

    for(int i = 0; i < 6; i++)
    {
        if (!visited[i])  // select 되지 않은 문자열들
        {
            str = v[i];
            if (!visited2[0] && str[1] == puzzle[1][0]
                && str[0] == puzzle[0][0] && str[2] == puzzle[2][0])
            {
                visited2[0] = true;
                flag ++;
            }
            else if (!visited2[1] && str[1] == puzzle[1][1]
                && str[0] == puzzle[0][1] && str[2] == puzzle[2][1])
            {
                visited2[1] = true;
                flag ++;
            }
            else if (!visited2[2] && str[1] == puzzle[1][2]
                && str[0] == puzzle[0][2] && str[2] == puzzle[2][2])
            {
                visited2[2] = true;
                flag ++;
            }
        }
    }
    if (flag == 3)
        return (1);
    return (0);
}

// 가로에 쓸 문자열 3개를 고르는 함수
void select_str(void)
{
    if (puzzle.size() == 3)
    {
        if (is_right())  // 나머지 문자열 3개가 세로에 있는지 확인하는 함수
        {
            print_ans();
            exit(0);
        }
        return ;
    }

    for(int i = 0; i < 6; i++)  // 인덱스
    {
        if (!visited[i])
        {
            visited[i] = true;
            puzzle.push_back(v[i]);
            select_str();
            puzzle.pop_back();
            visited[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    select_str();
    cout << 0;
    return (0);
}
