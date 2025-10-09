// https://www.geeksforgeeks.org/problems/maximum-subarray-sum--110820/1

struct Node {
    int index_{};
    int value_{};
};

bool compare_node(const Node* lhs, const Node* rhs) {
    if (lhs->value_ == rhs->value_) {
        return lhs->index_ < rhs->index_;
    } else {
        return lhs->value_ < rhs->value_;
    }
}

class Solution {
public:
    int maxSubarrSum(std::vector<int>& arr, int a, int b) {
        int N = arr.size();
        std::vector<Node*> nodes{};
        int prefix_sum = 0;
        nodes.emplace_back(new Node{0, prefix_sum});
        for (int i=0; i<N; ++i) {
            int value = arr[i];
            prefix_sum = prefix_sum + value;
            nodes.emplace_back(new Node{i+1, prefix_sum});
        }

        int start = -1;
        int end = -1;
        int result = std::numeric_limits<int>::min();;
        std::vector<Node*> results{};
        Node* node = nullptr;
        for (int i=a; i<=N; ++i) {
            start = std::max(0, i - b);
            end = std::max(0, i - a);
            node = nodes[end];
            auto it = std::lower_bound(results.begin(), results.end(), node, compare_node);
            results.insert(it, node);
            node = nodes[i];
            result = std::max(result, node->value_ - results.front()->value_);
            if (i >= b) {
                node = nodes[start];
                auto it2 = std::lower_bound(results.begin(), results.end(), node, compare_node);
                results.erase(it2);
            }
        }
        return result;
    }
};

class Solution2 {
  public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int N = arr.size();
        int max = std::numeric_limits<int>::min();
        for (int i=a; i<=b; ++i) {
            int result = 0;
            for (int j=0; j<N; ++j) {
                int value = arr[j];
                if (j < i-1) {
                    result = result + value;
                } else if (j == i-1) {
                    result = result + value;
                    max = std::max(max, result);
                } else {
                    result = result - arr[j-i];
                    result = result + value;
                    max = std::max(max, result);
                }
            }
        }
        return max;
    }
};
