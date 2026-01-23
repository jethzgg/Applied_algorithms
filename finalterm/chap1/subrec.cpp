#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> a;
vector<int> heights;

int maxArea()
{
    stack<pair<int, int>> s;
    int area = 0;
    for (int i = 0; i < m; i++)
    {
        int start = i;
        while (!s.empty() && s.top().second > heights[i])
        {
            int index = s.top().first;
            int height = s.top().second;
            s.pop();
            area = max(area, height * (i - index));
            start = index;
        }
        s.push(make_pair(start, heights[i]));
    }
    while (!s.empty())
    {
        int index = s.top().first;
        int height = s.top().second;
        s.pop();
        area = max(area, height * (m - index));
    }
    return area;
}

int main()
{
    cin >> n >> m;
    a.resize(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    heights.resize(m, 0);
    int MAX = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 1) heights[j]++;
            else heights[j] = 0;
        }
        MAX = max(MAX, maxArea());
    }
    cout << MAX << "\n";
    return 0;
}