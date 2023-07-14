#include <bits/stdc++.h>
using namespace std;

class Participant {
    public:
        string name;
        vector<int> preferences;
        int currentPartner;
        int nextProposalIndex;
};

bool prefers(const Participant& participant, int partner, int potentialPartner) {
    const auto& preferences = participant.preferences;
    for (int i = 0 ; i < preferences.size() ; i++)
    {
        if (preferences[i] == potentialPartner)
            return true;
        if (preferences[i] == partner)
            return false;
    }
    return false;
}

vector<pair<string, string>> stableMatching(vector<Participant>& men, vector<Participant>& women) {
    int n = men.size();
    vector<pair<string,string>> matches(n);

    queue<int> freeMen;
    for (int i =0 ; i < n ;i++)
    {
        freeMen.push(i);
    }

    while (!freeMen.empty())
    {
        int m = freeMen.front();
        freeMen.pop();

        int w = men[m].preferences[men[m].nextProposalIndex];
        men[m].nextProposalIndex++;

        if (women[w].currentPartner == -1)
        {
            matches[w] = {men[m].name, women[w].name};
            women[w].currentPartner = m;
        }
        else if (prefers(women[w], women[w].currentPartner, m)) {
            int previousPartner = women[w].currentPartner;
            matches[w] = {men[m].name, women[w].name};
            women[w].currentPartner = m;
            freeMen.push(previousPartner);
        }
        else {
            freeMen.push(m);
        }
    }
    return matches;
}
int main() {
    vector<Participant> men = {
        {"M1", {0,1,2}, -1, 0},
        {"M2", {0,2,0}, -1, 0},
        {"M3", {2,1,0}, -1, 0}
    };
    vector<Participant> women = {
        {"W1", {1,2,0}, -1, 0},
        {"W2", {0,2,1}, -1, 0},
        {"W3", {1,0,2}, -1, 0}
    };

    vector<pair<string,string>> matches = stableMatching(men, women);

    cout << "Stable Matching :" << endl;
    for (const auto& match : matches) {
        cout << match.first << " - " << match.second << endl;
    }




    return 0;
}