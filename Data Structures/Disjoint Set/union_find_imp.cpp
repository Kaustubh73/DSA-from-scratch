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

        void union(int x, int y)
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

int main()
{   

    return 0;
}