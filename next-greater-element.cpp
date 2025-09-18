// https://www.geeksforgeeks.org/problems/next-greater-element/1
// Amazon, Microsoft

#include <stack>
#include <vector>


struct Node {
    int index_;
    int value_;
};

class Solution {

public:
    std::vector<int> nextGreater(std::vector<int>& values) {
        int N = values.size();
        std::vector<int> results(N, -1);
        std::stack<Node> nodes{};
        for (int i=0; i<N; ++i) {
            int value = values[i];
            while (!nodes.empty()) {
                Node& top = nodes.top();
                if (top.value_ < value) {
                    results[top.index_] = value;
                    nodes.pop();
                } else {
                    break;
                }
            }
            nodes.push(Node{i, value});
        }

        if (!nodes.empty()) {
            int bottom = nodes.top().index_;
            for (int i=0; i<bottom; ++i) {
                int value = values[i];
                while (!nodes.empty()) {
                    Node& top = nodes.top();
                    if (top.value_ < value) {
                        results[top.index_] = value;
                        nodes.pop();
                    } else {
                        break;
                    }
                }
            }    
        }
        
        return results;
    }
};
