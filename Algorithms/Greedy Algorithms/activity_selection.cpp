#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start, finish;
};

bool compareActivities(Activity a1, Activity a2) {
    return (a1.finish < a2.finish);
}

void printMaxActivities(vector<Activity>& activities) {
    sort(activities.begin(), activities.end(), compareActivities);

    int n = activities.size();
    int selectedCount = 1;
    vector<Activity> selectedAct;
    int prevFinishTime = activities[0].finish;
    selectedAct.push_back(activities[0]);
    for (int i = 1 ; i < n ; i++)
    {
        if (activities[i].start >= prevFinishTime)
        {
            selectedCount++;
            selectedAct.push_back(activities[i]);
            prevFinishTime = activities[i].finish;
        }
    }
    
    cout << "Maximum number of activities: " << selectedCount << endl;
    for (int i = 0 ; i < selectedAct.size() ; i++)
        cout << "Start - " << selectedAct[i].start << " Finish - " << selectedAct[i].finish << endl; 
}

int main() {

    vector<Activity> activities = {
        {1, 2},
        {3, 4},
        {0, 6},
        {5, 7},
        {8, 9},
        {5, 9}
    };

    // Call the function to print the maximum number of activities
    printMaxActivities(activities);

    return 0;
}