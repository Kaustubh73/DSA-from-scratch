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
        vector<int> indegree;
        vector<Edge> edges;
    
    public:
        Graph(int vertices) {
            n = vertices;
            adjList.resize(n);
            indegree.resize(n, 0);
        }

        void addEdge(int u, int v, int w)
        {
            if (u >= 0 && u < n && v >= 0 && v < n)
            {
                Edge e(u, v, w);
                adjList[u].push_back({v, w});
                edges.push_back(e);
                indegree[v]++;
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

        void topoSortUtil(int v, vector<bool>& visited, stack<int>& Stk)
        {
            visited[v] = true;

            for (auto edge : adjList[v]) 
            {
                if (!visited[edge.first])
                    topoSortUtil(edge.first, visited, Stk);
            }
            Stk.push(v);

        }

        void topoSort()
        {
            stack<int> Stk;
            vector<bool> visited(n, false);

            for (int i = 0 ; i < n ; i++)
            {
                if (!visited[i])
                {
                    topoSortUtil(i, visited, Stk);
                }
            }
            while (!Stk.empty()) {
                cout << Stk.top() << endl;
                Stk.pop();
            }

            // free(visited);
        }

        void kahnTopoSort() {
            queue<int> q;

            for (int i = 0 ; i < n ; i++)
            {
                if (indegree[i] == 0)
                {
                    q.push(i);
                }
            }

            int cnt = 0;

            vector<int> top_order;

            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                top_order.push_back(u);

                for (auto edge : adjList[u])
                {
                    if (--indegree[edge.first] == 0)
                        q.push(edge.first);
                }
                cnt++;
            }

            if (cnt != n) {
                cout << "There is a cycle!" << endl;
                return;
            }
            for (int i = 0 ; i < top_order.size() ; i++)
            {
                cout << top_order[i] << " ";
            }
            cout << endl;
        }

        void allTopoSortUtil(vector<int>& res, vector<bool>& visited)
        {
            bool flag = false;

            for (int i = 0 ; i < n ; i++)
            {
                if (indegree[i] == 0 && !visited[i])
                {
                    for (auto edge: adjList[i])
                    {
                        indegree[edge.first]--;
                    }
                    res.push_back(i);
                    visited[i] = true;
                    allTopoSortUtil(res, visited);
                    visited[i] = false;
                    res.pop_back();

                    for (auto edge : adjList[i])
                    {
                        indegree[edge.first]++;
                    }

                    flag = true;
                }
            }

            if (!flag)
            {
                for (int i = 0 ; i < res.size() ; i++)
                {
                    cout << res[i] <<  " ";
                }
                cout << endl;
            }
        }

        void allTopoSort()
        {
            vector<bool> visited(n, false);
            vector<int> res;
            allTopoSortUtil(res, visited);
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
    graph.kahnTopoSort();
    // cout << graph.edges << endl;

    return 0;
}