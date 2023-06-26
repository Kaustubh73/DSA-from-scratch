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
            adjacencyMatrix.resize(n, vector<int> (n, 0));
        }

        void addEdge(int u, int v) {
            if (u >= 0 && u < n && v >= 0 && v < n)
            {
                adjacencyMatrix[u][v] = 1;
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

};


int main()
{
    // Create a graph with 5 vertices
    Graph graph(5);

    // Add edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Print the adjacency matrix
    graph.DFS(0);

    return 0;
}