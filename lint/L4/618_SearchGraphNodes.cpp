/*Given a undirected graph, a node and a target, return the nearest node to given node which value of it is target, 
return NULL if you can't find.

There is a mapping store the nodes' values in the given parameters.*/


/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */


class Solution {
public:
    /*
     * @param graph: a list of Undirected graph node
     * @param values: a hash mapping, <UndirectedGraphNode, (int)value>
     * @param node: an Undirected graph node
     * @param target: An integer
     * @return: a node
     */
     UndirectedGraphNode* searchNode(vector<UndirectedGraphNode*>& graph,
                                    map<UndirectedGraphNode*, int>& values,
                                    UndirectedGraphNode* node,
                                    int target) {
        // write your code here
        queue<UndirectedGraphNode*> Q;
        set<UndirectedGraphNode*> hash;
        
        Q.push(node);
        hash.insert(node);
        
        while(!Q.empty()) {
            UndirectedGraphNode* head = Q.front();
            Q.pop();
            
            if (values[head] == target) {
                return head;
            }
            
            for (auto n: head->neighbors) {
                if (hash.find(n) == hash.end()) {
                    hash.insert(n);
                    Q.push(n);
                }
            }
        }
        return NULL;
    }
};
