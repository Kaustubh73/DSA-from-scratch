/*
    
*/
#include <bits/stdc++.h>
#include <utility>



using namespace std;

class Graph {
    private:
        vector<list<pair<int, int>>> adjList;
        int n;
    
    public:
        Graph(int vertices) {
            n = vertices;
            adjList.resize(n);
        }

        void addEdge(int u, int v, int w)
        {
            if (u >= 0 && u < n && v >= 0 && v < n)
            {
                adjList[u].push_back({v, w});
                adjList[v].push_back({u, w});
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

        void transposeGraph()
        {
            vector<list<pair<int, int>>> transpose;
            transpose.resize(n);
            for (int i = 0 ; i < n; ++i)
            {
                for (auto neighbor : adjList[i])
                {
                    transpose[neighbor.first].push_back({i, neighbor.second});
                }
            }
            adjList = transpose;
        }

        void BFS(int s)
        {
            vector<bool> visited;
            visited.resize(n, false);

            list<int> queue;

            visited[s] = true;
            queue.push_back(s);

            while (!queue.empty())
            {
                s = queue.front();
                cout << s << " ";
                queue.pop_front();

                for (auto adjacent : adjList[s])
                {
                    if (!visited[adjacent.first])
                    {
                        queue.push_back(adjacent.first);
                        visited[adjacent.first] = true;
                    }
                }
            }
            cout << endl;
        }

        // vector<int> dijkstra(int source) {
        //     vector<int> distances(n, INT_MAX);
        //     distances[source] = 0;

        //     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<
        // }
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
    graph.addEdge(2, 3, 12);
    graph.addEdge(3, 4, 12);

    // Print the adjacency list
    graph.BFS(0);
    graph.transposeGraph();
    graph.BFS(0);

    return 0;
}