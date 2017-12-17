/*Given a knight in a chessboard (a binary matrix with 0 as empty and 1 as barrier) with a source position, 
find the shortest path to a destination position, return the length of the route. 
Return -1 if knight can not reached.
If the knight is at (x, y), he can get to the following positions in one step:

(x + 1, y + 2)
(x + 1, y - 2)
(x - 1, y + 2)
(x - 1, y - 2)
(x + 2, y + 1)
(x + 2, y - 1)
(x - 2, y + 1)
(x - 2, y - 1)*/

//jiuzhang
/**
 * Definition for a point.
 * struct Point {
 *     int x, y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */


class Solution {
public:
    /*
     * @param grid: a chessboard included 0 (false) and 1 (true)
     * @param source: a point
     * @param destination: a point
     * @return: the shortest path 
     */
    int shortestPath(vector<vector<bool>> &grid, Point &source, Point &destination) {
        // write your code here
        int m = grid.size();
        int n = grid[0].size();
        
        vector< vector<int>> record(m, vector<int>(n, INT_MAX));
        record[source.x][source.y] = 0;
        
        vector<vector<int>> d = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}};
        
        queue<Point> Q;
        Q.push(source);
        while (!Q.empty()) {
            Point head = Q.front(); Q.pop();
            for (int k = 0; k < 8; ++k) {
                int x = head.x + d[k][0];
                int y = head.y + d[k][1];
                if (x>=0 && x<m && y >= 0 && y<n && !grid[x][y] && record[head.x][head.y] + 1 < record[x][y]) {
                    record[x][y] = record[head.x][head.y] +1;
                    Q.push (Point(x,y));
                }
            }
        }
        if (record[destination.x][destination.y] == INT_MAX) {
            return -1;
        }
        return record[destination.x][destination.y];
    }
};
