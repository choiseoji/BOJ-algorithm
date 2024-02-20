#include <iostream>
using namespace std;

long long A, B, C;

long long solve(long long a, long long b, long long c)
{
    if (b == 0)
        return (1);
    
    long long res = solve(a, b / 2, c);

    if (b % 2 == 1)
        return ((res * res) % c) * a % c;
    else
        return ((res * res) % c);
}

int main(void)
{
    long long A, B, C;
    
    cin >> A >> B >> C;
    cout << solve(A % C, B, C);
    return (0);
}