#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000

using namespace std;

int n, k1, k2;
vector <int> s0(MAX + 1);
vector <int> s1(MAX + 1);

int main()
{
    cin >> n >> k1 >> k2;
    s1[k1] = 1;
    s0[0] = 1;
    s0[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        s0[i] = s1[i - 1];
        s1[i] = 0;
        for (int j = k1; j <= k2; j++)
        {
            if ((i - j) >= 0)
                s1[i] += s0[i - j];
        }
    }
    cout << s1[n] + s0[n] << "\n";
    return 0;
}