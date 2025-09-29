#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), s(n+1);
    s[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s[i + 1] = s[i] + a[i];
    }

    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << s[b] - s[a - 1] << endl;
    }
    return 0;
}