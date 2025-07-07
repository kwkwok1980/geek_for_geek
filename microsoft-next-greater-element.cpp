// https://www.geeksforgeeks.org/problems/next-greater-element/1

struct Solution {
    
    struct Node {
        int index;
        int value;
    };
    
    std::vector<int> nextLargerElement(std::vector<int>& values) {
        int N = values.size();
        std::vector<int> results(N*2, -1);
        std::stack<Node> nodes{};
        for (int i=0; i<N*2; ++i) {
            Node node {i, values[i % N]};
            if (i == 0) {
                nodes.emplace(node);
            } else {
                while (!nodes.empty()) {
                    Node& top = nodes.top();
                    if (node.value > top.value) {
                        results[top.index] = node.value;
                        nodes.pop();
                    } else {
                        break;
                    }
                }
                nodes.emplace(node);
            }
        }
        results.resize(N);
        return results;
    }
      
    std::vector<int> nextLargerElement_bkp(std::vector<int>& values) {
        int N = values.size();
        std::vector<int> results{};
        for (int i=0; i<N; ++i) {
            int value = values[i];
            int found = -1;
            for (int j=1; j<N; ++j) {
                int index = (i + j) % N;
                if (values[index] > value) {
                    found = values[index];
                    break;
                }
            }
            results.emplace_back(found);
        }
        return results;
    }
};
