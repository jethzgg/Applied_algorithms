#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define MAX 100000

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    vector<int> A, B;
    map<int, int> c;
    int cnt = 0;

    cin >> n >> m;
    A.resize(n, 0);
    B.resize(m, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        c[A[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
        if (c[B[i]] != 0)
        {
            c[B[i]]--;
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}