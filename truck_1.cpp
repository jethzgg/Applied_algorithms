#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mode = 1e9 + 7;
int n, K, Q;
long long R;
int visited[13], d[13];
void TRY(int j, int nBox, int nCus)
{
    if (j > K)
    {
        if (nCus == n)
        {
            R++;
        }
        return;
    }
    if (nBox > 0) TRY(j + 1, 0, nCus);
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0 && nBox + d[i] <= Q)
        {
            visited[i] = 1;
            TRY(j, nBox + d[i], nCus + 1);
            visited[i] = 0;
        }
    }
}

int main()
{
    cin >> n >> K >> Q;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
        visited[i] = 0;
    }
    R = 0;
    TRY(1, 0, 0);
    int kfac = 1;
    for (int i = 2; i <= n; i++) kfac *= i;
    R = (R / kfac) % mode;
    cout << R;
    return 0;
}