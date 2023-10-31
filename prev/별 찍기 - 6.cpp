#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int k;

    cin >> N;
    k = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < k; j++)
            cout << " ";
        for(int j = k; j < (2 * N - 1) - k; j++)
        {
            cout << "*";
        }
        cout << "\n";
        k++;
    }
    return (0);
}