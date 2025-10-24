#include <iostream>
#include <vector>
#define MAX(a,b) (a < b) ? b : a
using namespace std;

int main()
{
    int n, Q, sum = 0;

    cin >> n >> Q;
    
    vector<int> a(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int i = 0, res = -1;
    for (int j = 0; j < n; j++)
    {
        sum += a[j];
        while (sum > Q)
        {
            sum -= a[i];
            i++;
        }
        res = MAX(res, j - i + 1);
    }
    if (sum == 0) res = -1;
    cout << res << "\n";
    return 0;
}