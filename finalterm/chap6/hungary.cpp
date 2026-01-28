#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const long long INF = 1e18; // Giá trị vô cực lớn cho long long

int n, m, k, sz;
vector<vector<long long>> a; // Ma trận chi phí (đã đảo dấu)
vector<long long> u, v, minv; 
vector<int> p, way; // p: mảng matching, way: mảng truy vết

int main()
{
    if (!(cin >> n >> m >> k)) return 0;

    sz = max(n, m);
    a.assign(sz + 1, vector<long long>(sz + 1, 0));

    for (int i = 0; i < k; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        if (a[x][y] == 0) a[x][y] = -w; 
        else a[x][y] = min(a[x][y], (long long)-w);
    }

    u.assign(sz + 1, 0);
    v.assign(sz + 1, 0);
    p.assign(sz + 1, 0);
    way.assign(sz + 1, 0);
    for (int i = 1; i <= sz; i++)
    {
        p[0] = i;
        int j0 = 0;
        minv.assign(sz + 1, INF);
        vector<bool> used(sz + 1, false);

        do
        {
            used[j0] = true;
            int i0 = p[j0];
            long long delta = INF;
            int j1;

            for (int j = 1; j <= sz; j++)
            {
                if (!used[j])
                {
                    long long cur = a[i0][j] - u[i0] - v[j];
                    if (cur < minv[j])
                    {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if (minv[j] < delta)
                    {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }

            for (int j = 0; j <= sz; j++)
            {
                if (used[j])
                {
                    u[p[j]] += delta;
                    v[j] -= delta;
                }
                else
                {
                    minv[j] -= delta;
                }
            }
            j0 = j1;
        } while (p[j0] != 0);

        do
        {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0 != 0);
    }
    cout << v[0] << "\n";

    return 0;
}