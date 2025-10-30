#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000

using namespace std;

int T, N, C, ans;
vector<int> a(MAX);

void merge(vector<int> &a, int l, int m, int r)
{
    int len1 = m - l + 1;
    int len2 = r - m;
    vector<int> left(len1), right(len2);
    for (int i = 0; i < len1; i++) left[i] = a[i + l];
    for (int i = 0; i < len2; i++) right[i] = a[i + m + 1];
    int i = 0, j = 0;
    while (i < len1 && j < len2)
    {
        if (left[i] < right[j])
        {
            a[l++] = left[i++];
        }
        else
        {
            a[l++] = right[j++];
        }
    }
    while (i < len1)
    {
        a[l++] = left[i++];
    }
    while (j < len2)
    {
        a[l++] = right[j++];
    }
}

void mergesort(vector<int> &a, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        merge(a, l, m ,r);
    }
}

int check(int d)
{
    int load = 1;
    int last = a[0];
    for (int i = 1; i < N; i++)
    {
        if ((a[i] - last) >= d)
        {
            load++;
            last = a[i];
        }
        if (load == C) return 1;
    }
    return 0;
}

void res(int l, int h)
{
    if (l <= h)
    {
        int m = l + (h - l) / 2;
        if (check(m) == 1) 
        {
            ans = m;
            res(m + 1, h);
        }
        else
        {
            res(l, m - 1);
        }
    }
}

int main()
{
    cin >> T;
    while (T--)
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        cin >> N >> C;
        for (int i = 0; i < N; i++)
        {
            cin >> a[i];
        }
        mergesort(a, 0, N - 1);
        int d = (a[N - 1] - a[0]) / (C - 1);
        res(1, d);
        cout << ans << "\n";
    }
    return 0;
}