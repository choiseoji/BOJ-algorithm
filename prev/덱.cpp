#include <iostream>
using namespace std;
const int MAX = 10001;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int num;
    int head = MAX;
    int tail = MAX;
    int arr[2 * MAX + 1];

    cin >> N;
    while (N--)
    {
        string str;

        cin >> str;
        if (str == "push_front")
        {
            cin >> num;
            arr[--head] = num;
        }
        else if (str == "push_back")
        {
            cin >> num;
            arr[tail++] = num;
        }
        else if (str == "pop_front")
        {
            if (head == tail)
                cout << -1 << "\n";
            else
            {
                cout << arr[head] << "\n";
                head++;
            }
        }
        else if (str == "pop_back")
        {
             if (head == tail)
                cout << -1 << "\n";
            else
            {
                cout << arr[tail - 1] << "\n";
                tail--;
            }
        }
        else if (str == "size")
        {
            cout << tail - head << "\n";
        }
        else if (str == "empty")
        {
            if (head == tail)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (str == "front")
        {
            if (head == tail)
                cout << -1 << "\n";
            else
                cout << arr[head] << "\n";
        }
        else if (str == "back")
        {
            if (head == tail)
                cout << -1 << "\n";
            else
                cout << arr[tail - 1] << "\n";
        }
    }
    return (0);
}