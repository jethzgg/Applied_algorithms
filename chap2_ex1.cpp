#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        map<int, int> m1;
        for (int i = 0; i < N; i++)
        {
            int x;
            cin >> x;
            m1[x]++;
        }
        for (int i = 0; i < M; i++)
        {
            int x;
            cin >> x;
            m1[x]--;
        }
        int count = 0;
        for (auto i : m1)
        {
            if (i.second != 0) count += abs(i.second);
        }
        cout << count << endl;
    }
    return 0;
}