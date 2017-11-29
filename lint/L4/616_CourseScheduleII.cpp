/*There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, 
for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs,
return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. 
If it is impossible to finish all courses, return an empty array.*/

//jiuzhang
class Solution {
public:
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: the course order
     */
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
        // write your code here
        vector<unordered_multiset<int>> edges(numCourses);
        vector<int> d(numCourses,0);
        for (int i = 0; i< prerequisites.size(); i++) {
            edges[prerequisites[i].second].insert(prerequisites[i].first);
            d[prerequisites[i].first]++;
        }
        
        queue<int> q;
        for (int i = 0; i<numCourses; i++){
            if(d[i] == 0)
                q.push(i);
        }
        
        vector<int> order;
        while ( !q.empty()) {
            int x = q.front(); q.pop();
            order.push_back(x);
            for( auto it = edges[x].begin(); it != edges[x].end(); it++) {
                d[*it]--;
                if (d[*it] == 0) {
                    q.push(*it);
                }
            }
        }
        if (order.size() == numCourses)
            return order;
        return vector<int>();
    }
};

