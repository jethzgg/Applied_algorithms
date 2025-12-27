#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, K, D;
    cin >> n >> K >> D;
    vector<int> a(n + 1, 0), prefix(n + 1, 0), dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }
    int Q = 0;
    for (int i = K; i <= n; i++)
    {
        if (prefix[i] - prefix[i - K] >= D)
        {   
            Q++;
        }
    }
    cout << Q << "\n";
    return 0;
}