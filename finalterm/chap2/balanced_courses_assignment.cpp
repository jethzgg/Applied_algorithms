#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int m, n;
int MIN = INT_MAX;
vector<vector<int>> course_lists;
vector<vector<int>> conflicts;
vector<int> assigns;
vector<int> loads;

int check(int course, int teacher)
{
    if (assigns[course] != -1) 
        return 0;
    if (find(course_lists[teacher].begin(), course_lists[teacher].end(), course) == course_lists[teacher].end())
        return 0;
    for (int i = 0; i < n; i++)
    {
        if (assigns[i] == teacher && conflicts[i][course] == 1)
            return 0;
    }
    return 1;
}

void assign(int course)
{
    if (assigns[course] == -1)
    {
        for (int teacher = 0; teacher < m; teacher++)
        {
            if (check(course, teacher))
            {
                assigns[course] = teacher;
                loads[teacher]++;
                if (course == (n - 1))
                {
                    MIN = min(MIN, *max_element(loads.begin(), loads.end()));
                }
                else
                {
                    int MAX = *max_element(loads.begin(), loads.end());
                    if (MAX <= MIN) assign(course + 1);
                }
                loads[teacher]--;
                assigns[course] = -1;
            }
        }
    }
}

int main()
{
    cin >> m >> n;
    course_lists.resize(m, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int course;
            cin >> course;
            course_lists[i].push_back(course - 1);
        }
    }
    int k;
    cin >> k;
    conflicts.resize(n, vector<int>(n, 0));
    while (k--)
    {
        int i, j;
        cin >> i >> j;
        conflicts[i - 1][j - 1] = 1;
        conflicts[j - 1][i - 1] = 1;
    }
    assigns.resize(n, -1);
    loads.resize(m, 0);
    assign(0);
    cout << MIN << "\n";
    return 0;
}