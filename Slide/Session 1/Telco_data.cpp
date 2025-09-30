#include <bits/stdc++.h>

using namespace std;

typedef struct call_info
{
    string from;
    string to;
    string date;
    int from_hour;
    int from_min;
    int from_sec;
    int to_hour;
    int to_min;
    int to_sec;
} call_info;

int check_number(string s)
{
    for (auto i : s)
    {
        if (!('0' <= i && i <= '9'))
        return 0;
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    call_info a;
    map<string, int> total_time, total_calls;
    string command;
    int check = 1;
    int total = 0;
    do
    {
        cin >> command;
        if (command == "#") break;

        char sep;
        cin >> a.from >> a.to >> a.date >> a.from_hour >> sep >> a.from_min >> sep >> a.from_sec >> a.to_hour >> sep >> a.to_min >> sep >> a.to_sec;

        total_calls[a.from]++;
        total_time[a.from] += ((a.to_hour - a.from_hour) * 3600 + (a.to_min - a.from_min) * 60 + (a.to_sec - a.from_sec));
        total++;
        check = check && check_number(a.from) && check_number(a.to);

    } while (command != "#");
    
    command = " ";

    do
    {
        cin >> command;
        if (command == "#") break;
        if (command == "?check_phone_number") cout << check << endl;
        if (command == "?number_calls_from")
        {
            string number;
            cin >> number;
            cout << total_calls[number] << endl;
        }
        if (command == "?count_time_calls_from")
        {
            string number;
            cin >> number;
            cout << total_time[number] << endl;
        }
        if (command == "?number_total_calls") cout << total << endl;

    } while (command != "#");
    
    return 0;
}
