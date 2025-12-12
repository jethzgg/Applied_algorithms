#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, C, d, res;
vector<int> a;

int check(int d)
{
    int last = a[0];
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if ((a[i] - last) >= d)
        {
            last = a[i];
            cnt++;
        }
        if (cnt == C) return 1;
    }
    return 0;
}

void binsearch(int low, int high)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (check(mid))
        {
            res = mid;
            binsearch(mid + 1, high);
        }
        else
            binsearch(low, mid - 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;

    while (T--)
    {
        cin >> n >> C;

        a.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        d = (a[n - 1] - a[0]) / (C - 1);
        binsearch(1, d);
        cout << res << "\n";
    }
    return 0;
}