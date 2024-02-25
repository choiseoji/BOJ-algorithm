#include <iostream>
#include <map>
using namespace std;

long long n;
map<long, long> m;

long long fib(long long n)
{
    if (m[n])
        return (m[n]);

    long long res;
    if (n % 2 == 0)
        res = fib(n / 2) * (fib(n / 2 + 1) + fib(n / 2 - 1)) % 1000000007;
    else
        res = ((fib((n + 1) / 2) * fib((n + 1) / 2) % 1000000007) + (fib((n - 1) / 2) * fib((n - 1) / 2) % 1000000007) % 1000000007);
    
    m[n] = res % 1000000007;
    return (m[n]);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    m[0] = 0;
    m[1] = 1;
    m[2] = 1;
    m[3] = 2;
    cout << fib(n);
    return (0);
}
