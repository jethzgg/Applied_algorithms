#include <bits/stdc++.h>

using namespace std;

int m, n;

int maxArea(vector<int> height)
{
    int max = 0;
    deque<pair<int, int>> st;
    for (int i = 0; i < m; i++)
    {
        int start = i;
        while (!st.empty() && st.back().second > height[i])
        {
            int index = st.back().first;
            int h = st.back().second;
            st.pop_back();
            max = __max(max, h * (i - index));
            start = index;
        }
        st.push_back({start, height[i]});
    }
    for (auto i : st)
    {
        max = __max(max, i.second * (m - i.first));
    }
    return max;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    int max = 0;

    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<int> count(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 1)
            {
                count[j]++;
            }
            else
            {
                count[j] = 0;
            }
        }
        max = __max(max, maxArea(count));
    }
    cout << max << endl;
    return 0;
}