class Solution {
public:
    vector<Node*> nodeMap;

    Solution() {
        nodeMap.assign(101, nullptr);
    }

    Node* getCloneNode(Node* prevNode) {
        Node* nnode = new Node(prevNode->val);
        nodeMap[prevNode->val] = nnode;
        return nnode;
    }

    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        queue<pair<Node*, Node*>> q;
        auto startNode = getCloneNode(node);
        q.push({ startNode, node });

        while (!q.empty()) {
            auto& nodePair = q.front();
            auto& newNode = nodePair.first; auto& preNode = nodePair.second;

            for (auto neighborNode : preNode->neighbors) {
                if (nodeMap[neighborNode->val] != nullptr) {
                    newNode->neighbors.push_back(nodeMap[neighborNode->val]);
                }
                else {
                    auto newNeighborNode = getCloneNode(neighborNode);
                    newNode->neighbors.push_back(newNeighborNode);
                    q.push({ newNeighborNode, neighborNode });
                }
            }

            q.pop();
        }

        return startNode;
    }
};