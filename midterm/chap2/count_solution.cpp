#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, M, cur = 0, cnt = 0;
vector<int> a, prefix;

void backtrack(int k)
{
    for (int i = 1; i <= M / a[k]; i++)
    {
        cur += i * a[k];
        if (k == n)
        {
            if (cur == M)
            {
                cnt++;
            }
        }
        else
        {
            int g = cur + prefix[n] - prefix[k];
            if (g <= M)
            {
                backtrack(k + 1);
            }
        }
        cur -= i * a[k];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> M;

    a.resize(n + 1, 0);
    prefix.resize(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }
    backtrack(1);
    cout << cnt << "\n";
    return 0;
}