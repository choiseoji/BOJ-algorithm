#include <iostream>
#include <vector>
using namespace std;

int N, num;
vector<int> v;
vector<int> l;

void input(void)
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        v.push_back(num);
    }
}

void binary_search(int idx)
{
    int left, right, mid;

    left = 0;
    right = l.size() - 1;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (l[mid] < v[idx])
            left = mid + 1;
        else
            right = mid;
    }
    l[left] = v[idx];    // 대체
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    for(int i = 0; i < N; i++)
    {
        if (l.size() == 0 || (l[l.size() - 1] < v[i]))
            l.push_back(v[i]);
        else
            binary_search(i);
    }
    cout << l.size();
    return (0);
}