// https://www.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1?page=1&status=attempted&sortBy=submissions
// Microsoft
// Amazon

struct Solution {
    
    int maxCircularSum(std::vector<int> &values) {
        int N = values.size();
        std::vector<int> results1(N, 0);
        std::vector<int> results2(N, 0);
        std::vector<int> results3(N, 0);
        std::vector<int> results4(N, 0);
        
        int value = 0;
        for (int i=0; i<N; ++i) {
            value = values[i];
            if (i == 0) {
                results1[i] = value;
            } else {
                results1[i] = std::max(results1[i-1] + value, value);
            }
        }

        int sum = 0;
        int max = std::numeric_limits<int>::min();
        for (int i=0; i<N; ++i) {
            value = values[i];
            if (i == 0){
                sum = value;
            } else {
                sum = sum + value;                
            }
            max = std::max(max, sum);
            results2[i] = max;
        }
        
        sum = 0;
        max = std::numeric_limits<int>::min();
        for (int i=N-1; i>=0; --i) {
            value = values[i];
            if (i == N-1){
                sum = value;
            } else {
                sum = sum + value;                
            }
            max = std::max(max, sum);
            results3[i] = max;
        }
        
        for (int i=0; i<N; ++i) {
            if (i == N-1) {
                results4[i] = results2[i];
            } else {
                results4[i] = results2[i] + results3[i+1];
            }
        }
        
        max = std::numeric_limits<int>::min();
        for (int i=0; i<N; ++i) {
            max =std::max(max, results1[i]);
            max =std::max(max, results4[i]);
        }
        return max;
    }
    
    struct Node {
        int index;
        int value;
        int start;
        int max;
    };
    
    
    int maxCircularSum_bkp(std::vector<int> &values) {
        int N = values.size();
        std::vector<Node*> nodes{};
        for (int i=0; i<2*N; ++i) {
            Node* node = new Node{};
            node->index = i;
            node->value = values[i % N];
            node->start = i;
            node->max = node->value;
            nodes.emplace_back(node);
        }
        for (int i=1; i<2*N; ++i) {
            Node* previous = nodes[i-1];
            Node* cursor = nodes[i];
            if (cursor->index - previous->start < N) {
                if (previous->max > 0) {
                    cursor->start = previous->start;
                    cursor->max = previous->max + cursor->value;
                }
            } else {
                if (previous->max - nodes[previous->start]->value > 0) {
                    cursor->start = previous->start + 1;
                    cursor->max = previous->max - nodes[previous->start]->value + cursor->value;
                }
            }
        }
        int result = std::numeric_limits<int>::min();
        for (int i=0; i<2*N; ++i) {
            result = std::max(result, nodes[i]->max);
        }
        return result;
    }
};
