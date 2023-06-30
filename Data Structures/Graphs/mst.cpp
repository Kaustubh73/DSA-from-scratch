/*
    
*/
#include <bits/stdc++.h>
#include <utility>



using namespace std;
class UnionFind {
    private:
        vector<int> parent;
        vector<int> rank;
    
    public:
        UnionFind(int n)
        {
            parent.resize(n, -1);
            rank.resize(n, 1);
        }

        int find(int x)
        {
            if (parent[x] == -1)
                return x;
            parent[x] = find(parent[x]);

            return parent[x];
        }

        void unite(int x, int y)
        {
            int s1 = find(x);
            int s2 = find(y);

            if (s1 != s2) {
                if (rank[s1] < rank[s2]) {
                    parent[s2] = s1;
                }
                else if (rank[s1] > rank[s2]) {
                    parent[s1] = s2;
                }
                else {
                    parent[s2] = s1;
                    rank[s1] += 1;
                }
            }
        }
    
};

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
        
        void primMST() 
        {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

            int s = 0;
            vector<int> minDist (n, INT_MAX);

            vector<int> parent(n , -1);

            vector<bool> inMST(n , false);

            pq.push({0, s});
            minDist[s] = 0;

            while (!pq.empty())
            {
                int u = pq.top().second;
                pq.pop();
                if (inMST[u] == true)
                    continue;
                inMST[u] = true;

                for (auto edge : adjList[u])
                {
                    int v = edge.first;
                    int weight = edge.second;

                    if (!inMST[v] && weight < minDist[v])
                    {
                        parent[v] = u;
                        minDist[v] = weight;
                        pq.push({minDist[v], v});
                    }
                }
            }

            // Print the minimum spanning tree
            cout << "Minimum Spanning Tree:\n";
            for (int i = 1; i < n; ++i) {
                cout << parent[i] << " : " << i << endl;
            }
        }

        void kruskalsMST()
        {
            sort(edges.begin(), edges.end(), compareEdges);

            UnionFind S(n);
            int ans = 0;
            for (auto edge : edges)
            {
                int w = edge.weight;
                int x = edge.src;
                int y = edge.dest;

                if (S.find(x) != S.find(y)) {
                    S.unite(x, y);
                    ans += w;
                    cout << x << " -- " << y << " == " << w << endl;
                }
            }
            cout << "Minimum Cost of the Spanning Tree: " << ans;
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