/*Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), 
write a function to check whether these edges make up a valid tree.*/

//note: acyclic graph? connected graph?
/*Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

// BFS
class Solution {
public:
    /*
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
        vector<unordered_set<int>> g(n, unordered_set<int>());
        unordered_set<int> v;
        queue<int> q;
        q.push(0);
        v.insert(0);
        for(auto a : edges) {
            g[a[0]].insert(a[1]);
            g[a[1]].insert(a[0]);
        }
        while (!q.empty()) {
            int c = q.front(); q.pop();
            for (auto a :g[c]) {
                if (v.find(a)!=v.end()) return false;
                v.insert(a);
                q.push(a);
                g[a].erase(c);
            }
        }
        return v.size() == n;
    }
};

//jiuzhang-union-find

class Solution {
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>>& edges) {
        // Write your code here
        vector<int> root(n, -1);
        for(int i = 0; i < edges.size(); i++) {
            int root1 = find(root, edges[i][0]);
            int root2 = find(root, edges[i][1]);
            if(root1 == root2)
                return false;
            root[root1] = root2;
        }
        return edges.size() == n - 1;
    }
    int find(vector<int> &root, int e) {
        if(root[e] == -1)
            return e;
        else
            return root[e] = find(root, root[e]);
    }
};
