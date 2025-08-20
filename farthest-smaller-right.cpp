// https://www.geeksforgeeks.org/problems/farthest-smaller-right/1

struct Node {
    int index;
    int value;
};

bool operator<(const Node& lhs, const Node& rhs) {
    return lhs.value < rhs.value;
}

struct Solution {
    std::vector<int> farMin(std::vector<int>& values) {
        int N = values.size();
        std::vector<int> results(N, -1);
        std::vector<Node> nodes{};
        for (int i=N-1; i>=0; --i) {
            int value = values[i];
            Node node{i, value};
            if (i != N-1) {
                auto it = std::lower_bound(nodes.begin(), nodes.end(), node);
                if (it == nodes.begin()) {
                    if (it->value > node.value) {
                        nodes.insert(it, node);
                    }
                } else {
                    it = it - 1;    
                    results[i] = it->index;
                }    
            } else {
                nodes.emplace_back(node);
            }
        }
        return results;
    }
};
