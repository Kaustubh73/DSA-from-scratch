/*
    
*/
#include <bits/stdc++.h>


using namespace std;

class Graph {
    private:
        vector<vector<int>> adjacencyMatrix;
        int n;
    public:
        Graph(int vertices) {
            n = vertices;
            adjacencyMatrix.resize(n, vector<int> (n, INT_MAX));

            for (int i = 0; i < n; ++i)
            {
                adjacencyMatrix[i][i] = 0;
            }
        }

        void addEdge(int u, int v, int w) {
            if (u >= 0 && u < n && v >= 0 && v < n)
            {
                adjacencyMatrix[u][v] = w;
                // adjacencyMatrix[v][u] = 1;
            }
        }

        void printGraph() {
            for (int i = 0 ; i < n ; i++)
            {
                for (int j = 0 ; j < n ; j++)
                {
                    cout << adjacencyMatrix[i][j] << " ";
                }
                cout << endl;
            }
        }

        void BFS(int s) {
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

                for (int i = 0 ; i < n; i++)
                {
                    if (adjacencyMatrix[i][s] == 1 && !visited[i])
                    {
                        queue.push_back(i);
                        visited[i] = true;
                    }
                }
            }
            cout << endl;
        }

        void DFS(int s) {
            vector<bool> visited(n, false);
            stack<int> stk;
            visited[s] = true;
            stk.push(s);

            while (!stk.empty())
            {
                s = stk.top();
                stk.pop();
                cout << s << " ";
                for (int i = 0 ; i < n; i++)
                {
                    if (adjacencyMatrix[s][i] && !visited[i])
                    {
                        visited[i] = true;
                        stk.push(i);
                    }
                }
            }
            cout << endl;
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
            for (int count = 0 ; count < n-1 ; count++)
            {
                int u = minDistance(dist, sptSet);

                sptSet[u] = true;

                for (int v = 0; v < n; v++)
                {
                    if (!sptSet[v] && adjacencyMatrix[u][v]
                        && dist[u] != INT_MAX && dist[u] + adjacencyMatrix[u][v] < dist[v])
                    {
                        dist[v] = dist[u] + adjacencyMatrix[u][v];
                    }
                }
            }
            printSolution(dist);
        }

        void floydWarshall() {
            vector<vector<int>> dist = adjacencyMatrix;
            
            for (int k = 0 ; k < n ; ++k)
            {
                for (int i = 0 ; i < n ; ++i)
                {
                    for (int j = 0 ; j < n; ++j)
                    {
                        if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                        {
                            dist[i][j] = dist[i][k] + dist[k][j];
                        }
                    }
                }
            }
            // Print the shortest distances
            cout << "Shortest distances between all pairs of vertices:\n";
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][j] == INT_MAX) {
                        cout << "INF\t";
                    } else {
                        cout << dist[i][j] << "\t";
                    }
                }
                cout << endl;
            }
        }

        void checkConnectivity() 
        {
            bool strongly = true;

            for (int i = 0 ; i < n ; i++)
            {
                for (int j = 0 ;  j < n ; j++)
                {
                    if (adjacencyMatrix[i][j] != adjacencyMatrix[j][i])
                    {
                        strongly = false;
                        break;
                    }
                }
                if (!strongly)
                    break;
            }

            if (strongly) {
                cout << "Strongly Connected" << endl;
                return;
            }

            bool uppertri = true;
            
            for (int i = 0 ; i < n ;i++)
            {
                for (int j = i+1 ; j < n ; j++)
                {
                    if (adjacencyMatrix[i][j] == INT_MAX)
                    {
                        uppertri = false;
                        break;
                    }
                }
                if (!uppertri)
                    break;
            }

            if (uppertri) {
                cout << "Unilaterally Connected" << endl;
                return;
            }


            bool lowertri = true;
            
            for (int i = 0 ; i < n ;i++)
            {
                for (int j = i+1 ; j < n ; j++)
                {
                    if (adjacencyMatrix[j][i] == INT_MAX)
                    {
                        lowertri = false;
                        break;
                    }
                }
                if (!lowertri)
                    break;
            }

            if (lowertri) {
                cout << "Unilaterally Connected" << endl;
            }

            else {
                cout << "Weakly Connected" << endl;
            }

            return;
        }
};


int main()
{
    // Create a graph with 5 vertices
    Graph graph(3);

    // Add edges
    graph.addEdge(0, 1, 12);
    graph.addEdge(0, 2, 12);
    graph.addEdge(1, 0, 12);
    graph.addEdge(1, 2, 12);
    graph.addEdge(2, 1, 12);
    graph.addEdge(2, 0, 12);

    // Print the adjacency matrix
    // graph.dijkstra(1);
    graph.checkConnectivity();

    return 0;
}