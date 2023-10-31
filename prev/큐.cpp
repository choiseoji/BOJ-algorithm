#include <iostream>
using namespace std;
const int MAX=10001;

int N;
int q[MAX];
int head, tail;

void ft_push(int num)
{
    q[tail] = num;
    tail++;
}

void ft_pop(void)
{
    if (head == tail)
        cout << -1 << "\n";
    else
    {
        cout << q[head] << "\n";
        head++;
    }
}

void ft_size(void)
{
    cout << tail - head << "\n";
}

void ft_empty(void)
{
    if (head == tail)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";
}

void ft_front(void)
{
    if (head == tail)
        cout << -1 << "\n";
    else
        cout << q[head] << "\n";
}

void ft_back(void)
{
    if (head == tail)
        cout << -1 << "\n";
    else
        cout << q[tail - 1] << "\n";
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    head = 0;
    tail = 0;
    while (N--)
    {
        string cmd;

        cin >> cmd;
        if (cmd == "push")
        {
            int num; cin >> num;
            ft_push(num);
        }
        else if (cmd == "pop")
            ft_pop();
        else if (cmd == "size")
            ft_size();
        else if (cmd == "empty")
            ft_empty();
        else if (cmd == "front")
            ft_front();
        else if (cmd == "back")
            ft_back();
    }
    return (0);
}