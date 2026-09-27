// https://www.geeksforgeeks.org/problems/pizza-mania0155/1

class Solution {
public:
    constexpr static int MAX = std::numeric_limits<int>::max();

    int minimumCost(int x, int s, int m, int l, int cs, int cm, int cl) {
        std::unordered_map<int, int> results{};
        std::unordered_map<int, int> costs {{s, cs}, {m, cm}, {l, cl}};
        int result = MAX;
        for (int i=0; i<x+l; ++i) {
            if (i == 0) {
                results[i] = 0;
                continue;
            }
            results[i] = MAX;
            for (auto [size , cost] : costs) {
                int j = i - size;
                if (j >= 0 && results[j] != MAX) {
                    results[i] = std::min(results[i], results[j] + cost);
                }
            }
            if (i >= x)
            {
                result = std::min(result, results[i]);
            }
        }
        return result;
    }
};
