#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef struct
{
    string className;
    int classDuration;
    int studentsNumber;
} Class;

typedef struct 
{
    string roomName;
    int capacity;
    int durationsNumber;
    vector<pair<int, int>> listDurations;
} Room;

int n, m;
vector<Class> listClass;
vector<Room> listRoom;
vector<vector<vector<int>>> used;
int cnt = 0;

int durationCheck(int i, int j, int start, int kClass)
{
    if (listClass[kClass].classDuration > listRoom[i].listDurations[j].second) return 0;
    for (int end = start; end < (start + listClass[kClass].classDuration); end++)
    {
        if (used[i][j][end] == 1)
        {
            return 0;
        }
    }
    return 1;
}

void backtrack(int kClass)
{
    if (kClass == n)
    {
        cnt++;
        return;
    }
    for (int i = 0; i < m; i++)
    {
        if (listRoom[i].capacity >= listClass[kClass].studentsNumber)
        {
            for (int j = 0; j < listRoom[i].durationsNumber; j++)
            {
                for (int t = listRoom[i].listDurations[j].first; t <= (listRoom[i].listDurations[j].first + listRoom[i].listDurations[j].second - listClass[kClass].classDuration); t++)
                {
                    if (durationCheck(i, j, t, kClass))
                    {
                        for (int t1 = t; t1 < (t + listClass[kClass].classDuration); t1++) 
                            used[i][j][t1] = 1;
                        backtrack(kClass + 1);
                        for (int t1 = t; t1 < (t + listClass[kClass].classDuration); t1++) 
                            used[i][j][t1] = 0;
                    }
                }
            }
        }
    }
}

int main()
{
    cin >> n;
    listClass.resize(n, Class());
    for (int i = 0; i < n; i++)
    {
        cin >> listClass[i].className >> listClass[i].classDuration >> listClass[i].studentsNumber;
    }
    cin >> m;
    used.resize(m, vector<vector<int>>());
    listRoom.resize(m, Room());
    for (int i = 0; i < m; i++)
    {
        cin >> listRoom[i].roomName >> listRoom[i].capacity >> listRoom[i].durationsNumber;
        used[i].resize(listRoom[i].durationsNumber, vector<int>());
        listRoom[i].listDurations.resize(listRoom[i].durationsNumber, {0, 0});
        for (int j = 0; j < listRoom[i].durationsNumber; j++)
        {
            cin >> listRoom[i].listDurations[j].first >> listRoom[i].listDurations[j].second;
            used[i][j].resize(listRoom[i].listDurations[j].first + listRoom[i].listDurations[j].second, 0);
        }
    }
    backtrack(0);
    cout << cnt << "\n";
    return 0;
}