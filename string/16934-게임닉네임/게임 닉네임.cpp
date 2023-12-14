#include <iostream>
#include <map>
using namespace std;

int N;
string name;
map<string, bool> m;
map<string, int> same_name;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> name;

        if (same_name[name] == 0)
        {
            same_name[name]++;
            int flag = 0;
            int idx = 0;
            string n = "";
            while (name[idx])
            {
                n += name[idx];
                if (m[n] == false)
                {
                    m[n] = true;
                    if (flag == 0)
                    {
                        cout << n << "\n";
                        flag++;
                    }
                }
                idx++;
            }
            if (flag == 0 && idx == name.size())
            {
                cout << name << "\n";
            }
        }
        else
        {
            same_name[name]++;
            cout << name << same_name[name] << "\n";
        }
    }
    return (0);
}