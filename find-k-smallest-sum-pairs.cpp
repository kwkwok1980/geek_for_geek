// https://www.geeksforgeeks.org/problems/find-k-smallest-sum-pairs/1

struct Node {
    Node(int i, int j, int k) : x{i}, y{j}, value{k}{

    }

    int x{};
    int y{};
    int value{};
};

bool compare(const std::unique_ptr<Node>& lhs, const std::unique_ptr<Node>& rhs) {
    return lhs->value < rhs->value;
}

class Solution {
public:
    std::vector<std::vector<int>> kSmallestPair(std::vector<int>& arr1, std::vector<int>& arr2, int k) {
        std::vector<std::unique_ptr<Node>> nodes{};
        for (int x : arr1) {
            for (int y: arr2) {
                std::unique_ptr<Node> node = std::make_unique<Node>(x, y, x+y);
                auto it = std::lower_bound(nodes.begin(), nodes.end(), node, &compare);
                if (nodes.size() == k) {
                    if (it != nodes.end()) {
                        nodes.insert(it, std::move(node));
                        nodes.pop_back();
                    } else {
                        break;
                    }
                } else {
                    nodes.insert(it, std::move(node));
                }
            }
        }
        std::vector<std::vector<int>> results{};
        for (const auto& node : nodes) {
            results.emplace_back(std::vector{node->x, node->y});
        }
        return results;
    }
};
