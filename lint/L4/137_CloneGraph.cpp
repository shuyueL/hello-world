/*Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

How we serialize an undirected graph:

Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.

As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.*/

// BFS:
* Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */


class Solution {
public:
    /*
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        // write your code here
        if (!node) return nullptr;
        UndirectedGraphNode *p1 = node;
        UndirectedGraphNode *p2 = new UndirectedGraphNode (node->label);
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        map[node] = p2;
        
        while (!q.empty()) {
            p1 = q.front(); p2 = map[p1];
            q.pop();
            for (int i =0; i<p1->neighbors.size(); i++) {
                UndirectedGraphNode* nb = p1->neighbors[i];
                if (map.count(nb)) {
                    p2->neighbors.push_back(map[nb]);
                } else{
                    UndirectedGraphNode *temp = new UndirectedGraphNode (nb->label);
                    p2->neighbors.push_back(temp);
                    map[nb] = temp;
                    q.push(nb);
                }
            }
        }
        return map[node];
    }
};


//jiuzhang-DFS:
class Solution {
public:
    UndirectedGraphNode *clone(UndirectedGraphNode *node, map<int,UndirectedGraphNode*> &table)
    {
        if(node==NULL)
            return NULL;
            
        if(table.find(node->label)!=table.end())
            return table[node->label];
        
        UndirectedGraphNode *newnode=new UndirectedGraphNode(node->label);
        table[newnode->label]=newnode;

        for(int i=0;i<node->neighbors.size();i++)
        {
            UndirectedGraphNode *neighbor=clone(node->neighbors[i],table);
            newnode->neighbors.push_back(neighbor);
        }
        
        return newnode;
    }
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        map<int,UndirectedGraphNode*> visitTable;
        return clone(node,visitTable);
    }
};
