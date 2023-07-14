#include <bits/stdc++.h>
using namespace std;

class Job {
    public:
        char id;
        int deadline;
        int profit;
};

bool sortByProfit(Job& j1, Job& j2) {
    return j1.profit > j2.profit;
}

pair<int, vector<char>> jobScheduling(vector<Job>& jobs)
{
    int n = jobs.size();
    vector<char> schedule(n, '-');
    sort(jobs.begin(), jobs.end(), sortByProfit);

    for (int i = 0 ; i < n ; i++)
    {
        int slot = jobs[i].deadline - 1;
        while (slot >= 0 && schedule[slot] != '-')
        {
            slot--;
        }

        if (slot >= 0) {
            schedule[slot] = jobs[i].id;
        }
    }

    int totalProfit = 0;
    for (int i =0 ; i < n ;i++)
    {
        if (schedule[i] != '-')
            totalProfit += jobs[i].profit;
    }

    return { totalProfit, schedule};
}

int main() 
{
    vector<Job> jobs = {
        {'A',2,100},
        {'B',1,19},
        {'C',2,27},
        {'D',1,25},
        {'E',3,15}
    };

    pair<int, vector<char>> result = jobScheduling(jobs);
    int totalProfit = result.first;
    vector<char> schedule = result.second;

    cout << "Schedule Jobs: ";
    for (char job : schedule) {
        if (job != '-')
            cout << job << " ";
    }
    cout << endl;

    cout << "Total Profit: " << totalProfit << endl;
    return 0;
}