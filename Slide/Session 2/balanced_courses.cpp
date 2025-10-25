#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define MAX_TEACHERS 10
#define MAX_COURSES 30

using namespace std;

int m, n;
vector<vector<int>> courses_list(MAX_TEACHERS);
vector<int> nbTeach(MAX_TEACHERS, 0);
vector<int> sols(MAX_COURSES, -1);
vector<vector<int>> conflicts(MAX_COURSES, vector<int>(MAX_COURSES, 0));
int MIN = MAX_COURSES;
int flag = 1;

int available(int i, int k)
{
    for (int j = 0; j < n; j++)
    {
        if (sols[j] == k)
        {
            if (conflicts[i][j] == 1) return 0;
        }
    }
    vector<int>::iterator it = find(courses_list[k].begin(), courses_list[k].end(), i);
    if (it == courses_list[k].end()) return 0;
    return 1;
}

void backtrack(int i)
{
    for (int k = 0; k < m; k++)
    {
        if (available(i, k) == 1)
        {
            sols[i] = k;
            nbTeach[k]++;
            if (i == (n - 1))
            {
                int MAX = 0;
                for (int j = 0; j < m; j++)
                {
                    if (MAX < nbTeach[j]) MAX = nbTeach[j];
                }
                if (MIN > MAX) MIN = MAX;
                flag = 0;
            }
            else
            {
                int MAX = 0;
                for (int j = 0; j < m; j++)
                {
                    if (MAX < nbTeach[j]) MAX = nbTeach[j];
                }
                if (MIN > MAX) backtrack(i + 1);
            }
            sols[i] = -1;
            nbTeach[k]--;
        }
    }
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int a;
            cin >> a;
            courses_list[i].push_back(a - 1);
        }
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        conflicts[a - 1][b - 1] = 1;
        conflicts[b - 1][a - 1] = 1;
    }
    backtrack(0);
    cout << (flag ? -1 : MIN) << "\n";
    return 0;
}