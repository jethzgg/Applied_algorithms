#include <iostream>
#include <vector>
#define MAX 100000

using namespace std;

int n, M;
vector<int> a(MAX), prefix_sum(MAX, 0);
int res = 0;
int sum = 0;

void backtrack(int k)
{
    for (int i = 1; i <= M / a[k]; i++)
    {
        sum += (i * a[k]);
        if (k == (n - 1))
        {
            if (sum == M) res++;
        }
        else
        {
            sum -= (i * a[k]);
            int g = (M - sum - (prefix_sum[n - 1] - prefix_sum[k])) / a[k];
            sum += (i * a[k]);
            if (i <= g) backtrack(k + 1);
        }
        sum -= (i * a[k]);
    }
}

int main()
{
    cin >> n >> M;
    cin >> a[0];
    prefix_sum[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
    }
    backtrack(0);
    cout << res << "\n";
    return 0;
}