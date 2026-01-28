#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int n, c, res;
vector<int> a;
int check(int d)
{
    int last = 0;
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] - a[last] >= d)
        {
            cnt++;
            last = i;
        }
        if (cnt == c)
        {
            return 1;
        }
    }
    return 0;
}
void findD(int left, int right)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;
        
        if (check(mid))
        {
            res = mid;
            findD(mid + 1, right);
        }
        else
        {
            findD(left, mid - 1);
        }
    }
}

int main()
{   
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> c;
        a.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int d = (a[n - 1] - a[0]) / (c - 1);
        
        findD(1, d);

        cout << res << "\n";
    }
    return 0;
}