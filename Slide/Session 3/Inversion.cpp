#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000

using namespace std;

int n;
int a[MAX];
int Q = 0;
const int modulo = 1e9 + 7;

void merge(int a[], int l, int m, int r)
{
    int len1 = m - l + 1;
    int len2 = r - m;

    vector<int> b(len1), c(len2);
    for (int i = 0; i < len1; i++) b[i] = a[i + l];
    for (int i = 0; i < len2; i++) c[i] = a[i + m + 1];

    int i = 0, j = 0, l1 = l;
    while (i < len1 && j < len2)
    {
        if (b[i] > c[j])
        {
            Q = (Q + m - (i + l1) + 1) % modulo;
            a[l++] = c[j++];
        }
        else
        {
            a[l++] = b[i++];
        }
    }
    while (i < len1)
    {
        a[l++] = b[i++];
    }
    while (j < len2)
    {
        a[l++] = c[j++];
    }
}

void mergesort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    mergesort(a, 0, n - 1);
    cout << Q << "\n";
    return 0;
}