#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    string s = "";
    int k;
    while (s != "#")
    {
        cin >> s;
        if (s == "#") break;
        cin >> k;
        vector<int>::iterator it = upper_bound(a.begin(), a.end(), k);
        if (it == a.end()) cout << -1 << endl;
        else cout << *it << endl;
    }
    return 0;
}