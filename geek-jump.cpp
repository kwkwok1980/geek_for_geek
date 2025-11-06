// https://www.geeksforgeeks.org/problems/geek-jump/1

class Solution {
  public:
    int minCost(vector<int>& height) {
        int N = height.size();
        std::vector<int>results(N, 0);
        results[0] = 0;
        results[1] = std::abs(height[1] - height[0]);
        for (int i=2; i<N; ++i) {
            int result1 = results[i-2] + std::abs(height[i] - height[i-2]);
            int result2 = results[i-1] + std::abs(height[i] - height[i-1]);
            results[i] = std::min(result1, result2); 
        }
        return results[N-1];
    }
};
