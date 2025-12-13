#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, K1, K2;
vector<int> s0, s1;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> K1 >> K2;
    s0.resize(n + 1, 0);
    s1.resize(n + 1, 0);

    s0[0] = 1;
    s0[1] = 1;
    s1[K1] = 1;
    s0[K1] = 0;

    for (int i = K1 + 1; i <= n; i++)
    {
        s0[i] = s1[i - 1];
        s1[i] = 0;
        for (int j = K1; j <= K2; j++)
        {
            s1[i] = s1[i] + s0[i - j];
        }
    }
    cout << s0[n] + s1[n] << "\n";
    return 0;
}