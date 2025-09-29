#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, Q;
    cin >> n >> Q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int M = 0, i = 0, j = n - 1;
    while (i < j)
    {
        if ((a[i] + a[j]) == Q)
        {
            M++;
            i++;
            j--;
        }
        else if ((a[i] + a[j]) < Q)
        {
            i++;
        }
        else j--;
    }
    cout << M << endl;
    return 0;
}