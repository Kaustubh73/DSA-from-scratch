#include <bits/stdc++.h>

using namespace std;


class Graph {
    private:
        int n;
        vector<vector<int>> capacity;
        vector<vector<int>> flow;
    

    public:
        Graph(int vertices) {
            n = vertices;
            capacity.resize(n, vector<int>(n,0));
            flow.resize(n, vector<int>(n,0));
        }

        void addEdge(int u, int v) {
            capacity[u][v] = 1;
        }

        int fordFulkerson(int source, int sink) {
            int maxFlow = 0;
            vector<int> parent(n);

            while (bfs(source, sink, parent)) {
                int pathFlow = INT_MAX;
                for (int v = sink; v!= source; v = parent[v]) {
                    int u = parent[v];
                    pathFlow = min(pathFlow, capacity[u][v] - flow[u][v]);
                }

                for (int v = sink ; v != source ; v = parent[v]) {
                    int u = parent[v];
                    flow[u][v] += pathFlow;
                    flow[v][u] -= pathFlow;
                }

                maxFlow += pathFlow;
            }

            return maxFlow;
        }
    
    private:
        bool bfs(int source, int sink, vector<int>& parent) {
            vector<bool> visited(n, false);
            queue<int> q;

            q.push(source);
            visited[source] = true;
            parent[source] = -1;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v = 0 ; v < n ; ++v)
                {
                    if (!visited[v] && capacity[u][v] > flow[u][v])
                    {
                        q.push(v);
                        parent[v] = u;
                        visited[v] = true;
                    }
                }
            }

            return visited[sink];
        }
};

int main() {

    Graph graph(8);

    // Add edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    graph.addEdge(2, 6);
    graph.addEdge(2, 3);
    graph.addEdge(3, 6);
    graph.addEdge(4, 2);
    graph.addEdge(4, 7);
    graph.addEdge(5, 4);
    graph.addEdge(5, 7);
    graph.addEdge(5, 1);
    graph.addEdge(6, 5);
    graph.addEdge(6, 7);


    int source = 0;
    int sink = 7;

    // Find the maximum flow using the Ford-Fulkerson algorithm
    int maxFlow = graph.fordFulkerson(source, sink);

    cout << "There are " << maxFlow << " Disjoint edges between " << source << " and " << sink << endl;
    
}