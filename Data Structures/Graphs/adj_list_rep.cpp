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

        Graph transposeGraph()
        {
            Graph transpose(n);
            for (int i = 0 ; i < n; ++i)
            {
                for (auto neighbor : adjList[i])
                {
                    transpose.addEdge(neighbor.first, i, neighbor.second);
                }
            }
            return transpose;
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

        void DFSUtil(int v, vector<bool>& visited, vector<int>& component) {
            visited[v] = true;
            component.push_back(v);

            for (auto neighbor : adjList[v]) {
                if (!visited[neighbor.first])
                {
                    DFSUtil(neighbor.first, visited, component);
                }
            }
        }

        void fillOrder(int v, vector<bool>& visited, stack<int>& stk) {
            visited[v] = true;

            for (auto neighbor : adjList[v]) {
                if (!visited[neighbor.first]) {
                    fillOrder(neighbor.first, visited, stk);
                }
            }
            stk.push(v);
        }

        void printSCCsKosaraju() {
            vector<bool> visited (n, false);
            stack<int> stk;

            for (int i = 0 ; i < n ; i++)
            {
                if (!visited[i]) {
                    fillOrder(i, visited, stk);
                }
            }

            Graph transpose = transposeGraph();

            vector<vector<int>> components;

            visited.assign(n, false);

            while (!stk.empty()) {
                int v =stk.top();
                stk.pop();

                if (!visited[v]) {
                    vector<int> component;
                    transpose.DFSUtil(v, visited, component);
                    components.push_back(component);
                }
            }

            cout << "Strongly Connected Components:\n";
            for (auto component : components) {
                for (int vertex : component) {
                    cout << vertex << " ";
                }
                cout << endl;
            }
        }

        void SCCUtil(int u, vector<int>& disc, vector<int>& low, stack<int>& stk, vector<bool>& inStack)
        {
            static int time = 0;
            time++;
            disc[u] = low[u] = time;
            stk.push(u);
            inStack[u] = true;

            for (auto edge : adjList[u])
            {
                int v = edge.first;

                if (disc[v] == -1) {
                    SCCUtil(v, disc, low, stk, inStack);

                    low[u] = min(low[u], low[v]);
                }
                else if (inStack[v])
                {
                    low[u] = min(low[u], disc[v]);
                }
            }

            int w = 0;
            if (low[u] == disc[u]) {
                while (stk.top() != u) {
                    w = stk.top();
                    cout << w << " ";
                    inStack[w] = false;
                    stk.pop();
                }
                w = stk.top();
                cout << w << endl;
                inStack[w] = false;
                stk.pop();
            }
        }

        void printSCCsTarjan()
        {
            vector<int> disc (n, -1);
            vector<int> low (n, -1);
            vector<bool> inStack (n, false);
            stack<int> stk;
            for (int i = 0 ; i < n ; i++)
            {
                if (disc[i] == -1)
                    SCCUtil(i, disc, low, stk, inStack);
            }
        }


};



int main()
{   
    cout << "\nSCCs in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0,12);
    g1.addEdge(0, 2,12);
    g1.addEdge(2, 1,12);
    g1.addEdge(0, 3,12);
    g1.addEdge(3, 4,12);
    g1.printSCCsTarjan();
 
    cout << "\nSCCs in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1,12);
    g2.addEdge(1, 2,12);
    g2.addEdge(2, 3,12);
    g2.printSCCsTarjan();
 
    cout << "\nSCCs in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1,12);
    g3.addEdge(1, 2,12);
    g3.addEdge(2, 0,12);
    g3.addEdge(1, 3,12);
    g3.addEdge(1, 4,12);
    g3.addEdge(1, 6,12);
    g3.addEdge(3, 5,12);
    g3.addEdge(4, 5,12);
    g3.printSCCsTarjan();
 
    cout << "\nSCCs in fourth graph \n";
    Graph g4(11);
    g4.addEdge(0, 1,12);
    g4.addEdge(0, 3,12);
    g4.addEdge(1, 2,12);
    g4.addEdge(1, 4,12);
    g4.addEdge(2, 0,12);
    g4.addEdge(2, 6,12);
    g4.addEdge(3, 2,12);
    g4.addEdge(4, 5,12);
    g4.addEdge(4, 6,12);
    g4.addEdge(5, 6,12);
    g4.addEdge(5, 7,12);
    g4.addEdge(5, 8,12);
    g4.addEdge(5, 9,12);
    g4.addEdge(6, 4,12);
    g4.addEdge(7, 9,12);
    g4.addEdge(8, 9,12);
    g4.addEdge(9, 8,12);
    g4.printSCCsTarjan();
 
    cout << "\nSCCs in fifth graph \n";
    Graph g5(5);
    g5.addEdge(0, 1,12);
    g5.addEdge(1, 2,12);
    g5.addEdge(2, 3,12);
    g5.addEdge(2, 4,12);
    g5.addEdge(3, 0,12);
    g5.addEdge(4, 2,12);
    g5.printSCCsTarjan();
 

    return 0;
}