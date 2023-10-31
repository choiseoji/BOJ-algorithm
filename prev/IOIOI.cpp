#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    int ans = 0;
    string S;

    cin >> N >> M >> S;
    for(int i = 0; i < M; i++)
    {
        int k = 0;
        if (S[i] == 'I')
        {
            while (S[i + 1] == 'O' && S[i + 2] == 'I')
            {
                k++;
                if (k == N)
                {
                    k--;
                    ans++;
                }
                i += 2;
            }
        }
    }
    cout << ans;
    return (0);
}