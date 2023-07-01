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

        void addEdge(int u, int v, int w) {
            capacity[u][v] = w;
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

    int n = 6;
    int m = 4; // Vertices in first bipartite set

    Graph graph(n + 2);
    int source = 0;
    int sink = n + 1;

    for (int i = 1 ; i <= m ; ++i)
    {
        graph.addEdge(source, i, 1);
    }

    for (int i = m + 1; i <= n ; ++i)
    {
        graph.addEdge(i, sink, 1);
    }

    graph.addEdge(1, m + 1, 1);
    graph.addEdge(2, m + 1, 1);
    graph.addEdge(2, m + 2, 1);
    graph.addEdge(3, m + 2, 1);
    graph.addEdge(4, m + 2, 1);

    // Find the maximum flow using the Ford-Fulkerson algorithm
    int maxFlow = graph.fordFulkerson(source, sink);

    cout << "Maximum Bipartite Matching : " << maxFlow << endl;
    
}