#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10

using namespace std;

int H, W, n;
vector<vector<int>> recs(MAX + 1, vector<int>(2));
vector<vector<int>> grid(MAX + 1, vector<int>(MAX, 0));

void place(int h, int w, int startRow, int startCol, int value)
{
    for (int i = startRow; i < startRow + h; i++)
    {
        for (int j = startCol; j < startCol + w; j++)
        {
            grid[i][j] = value;
        }
    }
}

int canPlace(int h, int w, int startRow, int startCol)
{
    if (((startRow + h - 1) > H) || ((startCol + w - 1) > W)) return 0;
    for (int i = startRow; i < startRow + h; i++)
    {
        for (int j = startCol; j < startCol + w; j++)
        {
            if (grid[i][j] == 1) return 0;
        }
    }
    return 1;
}

int backtrack(int k)
{
    if (k == n + 1) return 1;

    int h = recs[k][0];
    int w = recs[k][1];

    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (canPlace(h, w, i, j))
            {
                place(h, w, i, j, 1);
                if (backtrack(k + 1)) return 1;
                place(h, w, i, j, 0);
            }
            if (h != w && canPlace(w, h, i, j))
            {
                place(w, h, i, j, 1);
                if (backtrack(k + 1)) return 1;
                place(w, h, i, j, 0);
            }
        }
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> H >> W;
    cin >> n;
    int area = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> recs[i][0] >> recs[i][1];
        area += (recs[i][0] * recs[i][1]);
    }

    if (area > H * W)
    {
        cout << 0 << "\n";
        return 0;
    }

    sort(recs.begin() + 1, recs.end(), [](vector<int> a, vector<int> b){
        return a[0] * a[1] > b[0] * b[1];
    });

    cout << backtrack(1) << "\n";

    return 0;
}