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

        void addEdge(int u, int v, int c) {
            capacity[u][v] = c;
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

    Graph graph(6);

    // Add edges to the graph
    graph.addEdge(0, 1, 16);
    graph.addEdge(0, 2, 13);
    graph.addEdge(1, 2, 10);
    graph.addEdge(1, 3, 12);
    graph.addEdge(2, 1, 4);
    graph.addEdge(2, 4, 14);
    graph.addEdge(3, 2, 9);
    graph.addEdge(3, 5, 20);
    graph.addEdge(4, 3, 7);
    graph.addEdge(4, 5, 4);

    int source = 0;
    int sink = 5;

    // Find the maximum flow using the Ford-Fulkerson algorithm
    int maxFlow = graph.fordFulkerson(source, sink);

    cout << "Maximum Flow: " << maxFlow << endl;
    
}