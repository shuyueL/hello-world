/*Given a 2D grid, each cell is either a wall 2, a zombie 1 or people 0 (the number zero, one, two).
Zombies can turn the nearest people(up/down/left/right) into zombies every day, but can not through wall. 
How long will it take to turn all people into zombies? 
Return -1 if can not turn all people into zombies.*/

class Position {
public:
    int x;
    int y;
    Position(int _x, int _y):x(_x),y(_y) {}
};


class Solution {
public:
    /*
     * @param grid: a 2D integer grid
     * @return: an integer
     */
    int zombie(vector<vector<int>> &grid) {
        // write your code here
        int m = grid.size();
        int n = grid[0].size();
        
        queue<Position> q;
        
        for (int i = 0; i<m; i++){
            for (int j = 0; j<n; j++) {
                if(grid[i][j] == 1) {
                    q.push(Position(i,j));
                }
            }
        }
        
        int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int days = 0;
        while(!q.empty()) {
            days ++;
            int size = q.size();
            for (int i = 0;i < size;i++) {
                Position p = q.front(); 
                q.pop();
                for (int k = 0; k<4; k++) {
                    int x = p.x + d[k][0];
                    int y = p.y + d[k][1];
                    if (x >= 0 && x < m && y >=0 && y < n && grid[x][y] == 0) {
                        grid[x][y] = 1;
                        q.push(Position(x,y));
                    }
                }
            }
        }
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0)
                    return -1;

        return  days - 1;
    }
};
