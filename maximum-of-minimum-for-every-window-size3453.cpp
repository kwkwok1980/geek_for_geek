// https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1
// Amazon, Microsoft

struct Node {
    int index_{};
    int value_{};
    int left_{};
    int right_{};
    int length_{};
};

bool operator<(const Node& lhs, const Node& rhs) {
    if (lhs.value_ == rhs.value_) {
        return lhs.length_ > rhs.length_;
    } else {
        return lhs.value_ > rhs.value_;
    }
}

class Solution {
public:
    std::vector<int> maxOfMins(std::vector<int>& arr) {
        int N = arr.size();
        std::vector<Node> nodes{};
        for (int i=0; i<N; ++i) {
            Node node{.index_ = i, .value_ = arr[i], .left_ = -1, .right_ = N, .length_ = N};
            nodes.push_back(node);
        }
        std::stack<Node*> stacks{};
        for (int i=0; i<N; ++i) {
            Node& node = nodes[i];
            while (!stacks.empty()) {
                Node* top = stacks.top();
                if (node.value_ < top->value_) {
                    top->right_ = i;
                    stacks.pop();
                } else {
                    break;
                }
            }
            stacks.push(&node);
        }
        stacks = std::stack<Node*>{};
        for (int i=N-1; i>=0; --i) {
            Node& node = nodes[i];
            while (!stacks.empty()) {
                Node* top = stacks.top();
                if (node.value_ < top->value_) {
                    top->left_ = i;
                    stacks.pop();
                } else {
                    break;
                }
            }
            stacks.push(&node);
        }
        for (int i=0; i<N;++i) {
            Node& node = nodes[i];
            node.length_ = node.right_ - node.left_ - 1;
        }

        std::sort(nodes.begin(), nodes.end());
        std::vector<int> results(N, 0);
        int length = 1;
        for (int i=0; i<N; ++i) {
            Node& node = nodes[i];
            while (node.length_ >= length) {
                results[length-1] = node.value_;
                ++length;
            }
        }
        return results;
    }
};

class Solution2 {
  public:
    std::vector<int> maxOfMins(std::vector<int>& arr) {
        int N = arr.size();
        std::vector<int> results(N, std::numeric_limits<int>::min());
        for (int i=0; i<N; ++i) {
            int min = std::numeric_limits<int>::max();
            for (int j=i; j<N; ++j) {
                int value =arr[j];
                min = std::min(min, value);
                int& result = results[j-i];
                result = std::max(result, min);
            }
        }
        return results;
    }
};
