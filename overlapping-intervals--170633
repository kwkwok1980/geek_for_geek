// https://www.geeksforgeeks.org/problems/overlapping-intervals--170633/1

struct Node {
    int x;
    int y;
};

bool compare(const Node* lhs, const Node* rhs) {
    if (lhs->x == rhs->x) {
        return lhs->y < rhs->y;
    } else {
        return lhs->x < rhs->x;
    }
}

struct Solution {
    std::vector<std::vector<int>> mergeOverlap(std::vector<std::vector<int>>& arr) {
        std::vector<Node*> nodes{};
        for (const auto& pair : arr) {
            Node* node = new Node{pair[0], pair[1]};
            nodes.push_back(node);
            //std::cout << node->x << " node " << node->y << std::endl;
        }
        std::sort(nodes.begin(), nodes.end(), compare);
        Node* cursor = new Node{nodes[0]->x, nodes[0]->y};
        Node* next = nullptr;
        std::vector<std::vector<int>> results{};
        for (int i=1; i<nodes.size(); ++i) {
            next = nodes[i];
            //std::cout << cursor->x << " next " << cursor->y << std::endl;
            if (cursor->y < next->x) {
                results.push_back(std::vector{cursor->x, cursor->y});
                //std::cout << cursor->x << " " << cursor->y << std::endl;
                cursor->x = next->x;
                cursor->y = next->y;
            } else {
                if (cursor->y < next->y) {
                    cursor->y = next->y;
                }
            }
        }
        results.push_back(std::vector{cursor->x, cursor->y});
        //std::cout << cursor->x << " " << cursor->y << std::endl;
        return results;
    }
};
