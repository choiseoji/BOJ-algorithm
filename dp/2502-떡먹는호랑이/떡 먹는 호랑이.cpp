#include <iostream>
using namespace std;

int D, K;   // 넘어온 날, 떡의 개수
int b;
int A[33];
int B[33];

void get_dp(void)
{
    A[1] = 1;
    A[2] = 0;
    for(int i = 3; i <= D; i++)
    {
        A[i] = A[i - 1] + A[i - 2];
    }
    B[1] = 0;
    B[2] = 1;
    for(int i = 3; i <= D; i++)
    {
        B[i] = B[i - 1] + B[i - 2];
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> D >> K;
    get_dp();
    b = 2;
    while (1)
    {
        for(int a = 1; a <= b; a++)
        {
            if ((A[D] * a) + (B[D] * b) == K)
            {
                cout << a << "\n" << b;
                return (0);
            }
        }
        b++;
    }
    return (0);
}