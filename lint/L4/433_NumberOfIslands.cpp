/*Given a boolean 2D matrix, 0 is represented as the sea, 1 is represented as the island. 
If two 1 is adjacent, we consider them in the same island. 
We only consider up/down/left/right adjacent.
Find the number of islands.*/


// BFS: modified from jiuzhang java code, but TLE appears. I think the code is correct...Need to figure out why later.
class Coordinate {
public:
    int x;
    int y;
    Coordinate(int a, int b) {
        x = a;
        y = b;
    }
};

class Solution {
public:
    /*
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    int numIslands(vector<vector<bool>> &grid) {
        // write your code here
        if (grid.empty() || grid[0].empty()) return 0;
        int N = grid.size(), M = grid[0].size();
        int cnt = 0;
        
        for (int i = 0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (grid[i][j]) {
                    //cout<<'('<<i<<','<<j<<')'<<'\n';
                    BFS(grid, i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
    void BFS(vector<vector<bool>> &grid, int x, int y) {
        
        vector<int> dx = {0,1,-1,0};
        vector<int> dy = {1,0,0,-1};

        queue<Coordinate> myQueue;
        
        myQueue.push(Coordinate(x,y));
        grid[x][y] = false;
        
        while (!myQueue.empty()) {
            Coordinate front = myQueue.front();
            myQueue.pop();
            for (int k = 0; k<4; k++) {
                Coordinate adj = Coordinate(front.x +dx[k],front.y+dy[k]);
                if (check(adj,grid)) {
                    if (grid[adj.x][adj.y]) {
                        grid[adj.x][adj.y] = false;
                        myQueue.push(adj);
                    }
                }
            }
        }
        
    }
    
    bool check(Coordinate coor, vector<vector<bool>> grid) {
        int n = grid.size(), m = grid[0].size();
        return coor.x >=0 && coor.x<n && coor.y >=0 && coor.y <m;
    }
};

//jiuzhang DFS:
class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    void dfs(vector<vector<bool>> &grid, int x, int y) {
        if (x < 0 || x >= grid.size()) return;
        if (y < 0 || y >= grid[0].size()) return;
        if (!grid[x][y]) return;
        grid[x][y] = false;
        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
    }
    int numIslands(vector<vector<bool>>& grid) {
        // Write your code here
        if (grid.empty() || grid[0].empty()) return 0;
        int N = grid.size(), M = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (grid[i][j]) {
                    dfs(grid, i, j);
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};
