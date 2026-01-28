#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, M;
vector<int> a, prefix_sum, solution;
int sum = 0, cnt = 0;
void solve(int x)
{
    if (solution[x] == 0)
    {
        for (int i = 1; i <= (M / a[x]); i++)
        {
            solution[x] = i;
            sum += (i * a[x]);
            if (x == n)
            {
                if (sum == M)
                {
                    cnt++;
                }
            }
            else
            {
                int g = sum + prefix_sum[n] - prefix_sum[x];
                if (g <= M) solve(x + 1);
            }
            sum -= (i * a[x]);
            solution[x] = 0;
        }
    }
}

int main()
{
    cin >> n >> M;
    a.resize(n + 1, 0);
    prefix_sum.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
    }
    solution.resize(n + 1, 0);

    solve(1);
    cout << cnt << "\n";
    return 0;
}