#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int m, n, k;
vector<vector<int>> courses;
vector<vector<int>> conflicts;
vector<int> assign;
vector<int> countCourses;
int MIN = INT_MAX;

int check(int course, int teacher)
{
    if (assign[course] != -1) return 0;
    if (find(courses[teacher].begin(), courses[teacher].end(), course) == courses[teacher].end()) return 0;
    for (int i = 0; i < n; i++)
    {
        if (assign[i] == teacher && conflicts[course][i] == 1) return 0;
    }
    return 1;
}

void backtrack(int course)
{
    for (int teacher = 0; teacher < m; teacher++)
    {
        if (check(course, teacher))
        {
            assign[course] = teacher;
            countCourses[teacher]++;
            if (course == n - 1)
            {
                MIN = min(MIN, *max_element(countCourses.begin(), countCourses.end()));
            }
            else
            {
                if (*max_element(countCourses.begin(), countCourses.begin() + m) < MIN) 
                    backtrack(course + 1);
            }
            countCourses[teacher]--;
            assign[course] = -1;
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;

    courses.resize(m + 1);

    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int a;
            cin >> a;
            courses[i].push_back(a - 1);
        }
    }

    conflicts.resize(n, vector<int>(n, 0));

    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        conflicts[a - 1][b - 1] = 1;
        conflicts[b - 1][a - 1] = 1;
    }

    assign.resize(n, -1);
    countCourses.resize(m, 0);
    backtrack(0);
    cout << MIN << "\n";
    return 0;
}