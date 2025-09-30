#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    //preprocess
    vector<vector<int>> sparse(n, vector<int>(__lg(n) + 1));
        //sparse table M[i][log(n) + 1];
        //M[i][j] = min[start at i, length 2^j];
    for (int i = 0; i < n; i++) sparse[i][0] = i;
    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 0; i < n + 1 - (1 << j); i++)
        {
            if (a[sparse[i][j - 1]] < a[sparse[i + (1 << (j - 1))][j - 1]])
            {
                sparse[i][j] = sparse[i][j - 1];
            }
            else
            {
                sparse[i][j] = sparse[i + (1 << (j - 1))][j - 1];
            }
        }
    }

    //queries
    int q;
    cin >> q;
    int sum = 0;
    while (q--)
    {
        int b, c;
        cin >> b >> c;
        int k = __lg(c - b + 1);
        sum += __min(a[sparse[b][k]], a[sparse[c + 1 - (1 << k)][k]]);
    }
    cout << sum << endl;
    return 0;
}