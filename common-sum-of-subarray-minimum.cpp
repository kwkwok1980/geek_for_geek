// https://www.geeksforgeeks.org/problems/sum-of-subarray-minimum/1?page=1&status=attempted&sortBy=submissions

struct Solution {
    struct Node {
        int index;
        int value;
        int left;
        int right;
    };

    int sumSubMins(std::vector<int>& values) {
        std::vector<Node*> nodes{};
        int N = values.size();
        for (int i=0; i<N; ++i) {
            Node* node = new Node{};
            node->index = i+1;
            node->value = values[i];
            node->left = 0;
            node->right = N+1;
            nodes.emplace_back(node);
        }

        std::stack<Node*> leftNodes{};
        for (int i=0; i<N; ++i) {
            Node* node = nodes[i];
            while (!leftNodes.empty()) {
                Node* lefNode = leftNodes.top();
                if (node->value < lefNode->value) {
                    lefNode->right = node->index;
                    leftNodes.pop();
                } else {
                    break;
                }
            }
            leftNodes.push(node);
        }

        std::stack<Node*> rightNodes{};
        for (int i=N-1; i>=0; --i) {
            Node* node = nodes[i];
            while (!rightNodes.empty()) {
                Node* rightNode = rightNodes.top();
                if (node->value <= rightNode->value) {
                    rightNode->left = node->index;
                    rightNodes.pop();
                } else {
                    break;
                }
            }
            rightNodes.push(node);
        }
        int result = 0;
        for (int i=0; i<N; ++i) {
            Node* node = nodes[i];
            result = result + (node->index - node->left) * (node->right - node->index) * node->value;
        }
        return result;
    }


    int sumSubMins_bkp(std::vector<int>& values) {
        int N = values.size();
        int result = 0;
        for (int i=0; i<N; ++i) {
            int temp = std::numeric_limits<int>::max();
            for (int j=i; j<N; ++j) {
                temp = std::min(temp, values[j]);
                result = result + temp;
            }
        }
        return result;
    }
};
