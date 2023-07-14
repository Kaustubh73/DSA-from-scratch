#include <bits/stdc++.h>
using namespace std;

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& path, int pos)
{
    if (graph[path[pos -1]][v] == 0)
    {
        return false;
    }

    for (int i = 0 ; i < pos ; i++)
    {
        if (path[i] == v)
            return false;
    }
    return true;

}

bool hamiltonianCycleUtil(vector<vector<int>>& graph, vector<int>& path, int pos)
{
    if (pos == graph.size()) {
        if (graph[path[pos-1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1 ; v < graph.size() ; v++)
    {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (hamiltonianCycleUtil(graph, path, pos + 1))
                return true;
            
            path[pos] = -1;
        }
    }

    return false;
}

void hamiltonianCycle(vector<vector<int>>& graph) {
    int V = graph.size();

    vector<int> path (V, -1);

    path[0] = 0;
    
    if (hamiltonianCycleUtil(graph, path, 1)) {
        cout << "Hamiltonian Cycle found: ";
        for (int i = 0 ; i < V ; i++)
            cout << path[i] << " ";
        cout << path[0] << endl;
    }
    else
    {
        cout << "No Hamiltonian Cycle found!" << endl;
    }
}
int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    // Create the adjacency matrix representing the graph
    vector<vector<int>> graph(V, vector<int>(V, 0));
    cout << "Enter the adjacency matrix: " << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    hamiltonianCycle(graph);

    return 0;
}