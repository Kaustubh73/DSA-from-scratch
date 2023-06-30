/*
    
*/
#include <bits/stdc++.h>
#include <utility>



using namespace std;

class Edge {
    public:
        int src, dest, weight;
        Edge(int s, int d, int w) {
            src = s;
            dest = d;
            weight = w;
        }
        

};

bool compareEdges(const Edge& a, const Edge& b)
{
    return a.weight < b.weight;
}

class Graph {
    private:
        vector<list<pair<int, int>>> adjList;
        int n;
        // int edges = 0;
        vector<Edge> edges;
    
    public:
        Graph(int vertices) {
            n = vertices;
            adjList.resize(n);
        }

        void addEdge(int u, int v, int w)
        {
            if (u >= 0 && u < n && v >= 0 && v < n)
            {
                Edge e(u, v, w);
                adjList[u].push_back({v, w});
                edges.push_back(e);
                // edges++;
                // adjList[v].push_back({u, w});
            }
        }

        void printGraph() {
            for (int i  = 0 ; i < n ; ++i)
            {
                cout << "Vertex " << i << ": ";
                for (pair<int, int> neighbor : adjList[i])
                {
                    cout << neighbor.first << " ";
                }
                cout << endl;
            }
        }
        
        int minDistance(vector<int> dist, vector<bool> sptSet)
        {
            int min = INT_MAX, min_index;

            for (int v=  0 ; v < n; v++)
            {
                if (sptSet[v] == false && dist[v] <= min)
                {
                    min = dist[v];
                    min_index = v;
                }
            }
            return min_index;
        }

        void printSolution(vector<int> dist)
        {
            cout << "Vertex \t Distance from Source" << endl;
            for (int i = 0 ; i < n; i++)
            {
            if (dist[i] == INT_MAX) cout << i << " \t\t" << "INF" << endl;
            else cout << i << " \t\t" << dist[i] << endl;
            }
        }
        void dijkstra(int s) {
            vector<int> dist (n, INT_MAX);
            vector<bool> sptSet (n, false);

            dist[s] = 0;
            for (int i = 0 ; i < n-1 ; i++)
            {
                int u = minDistance(dist, sptSet);

                sptSet[u] = true;

                for (auto edge : adjList[u])
                {
                    int v = edge.first;
                    int weight = edge.second;

                    if (!sptSet[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
            printSolution(dist);
        }
        
        void dijkstra_pq(int s) {
            vector<int> dist (n, INT_MAX);
            vector<bool> sptSet (n, false);

            dist[s] = 0;
            
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, s});

            while (!pq.empty())
            {
                int u = pq.top().second;
                pq.pop();

                if (sptSet[u])
                    continue;
                
                for (auto& edge : adjList[u]) {
                    int v = edge.first;
                    int weight = edge.second;

                    if (!sptSet[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v])
                    {
                        dist[v] = dist[u] + weight;
                        pq.push({dist[v], v});
                    }
                }
            }
            printSolution(dist);
        }

        void BellmanFord(int s)
        {
            vector<int> dist (n, INT_MAX);

            dist[s] = 0;

            for (int i = 0 ; i < n-1; i++) 
            {
                for (auto& edge: edges) {
                    int u = edge.src;
                    int v = edge.dest;
                    int weight = edge.weight;

                    if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
                    {
                        dist[v] = dist[u] + weight;
                    }
                }
            }

            for (auto& edge : edges)
            {
                int u = edge.src;
                int v = edge.dest;
                int weight = edge.weight;

                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
                {
                    cout << "Graph contains negative weight cycles\n";
                    return;
                }
            }

            printSolution(dist);
            return;
        }


};



int main()
{   
    Graph graph(5);
    // Add edges
    graph.addEdge(0, 1, 12);
    graph.addEdge(0, 4, 12);
    graph.addEdge(1, 2, 12);
    graph.addEdge(1, 3, 12);
    graph.addEdge(1, 4, 12);
    graph.addEdge(2, 4, 12);
    graph.addEdge(3, 4, 12);

    // Print the adjacency list
    graph.kruskalsMST();
    // cout << graph.edges << endl;

    return 0;
}