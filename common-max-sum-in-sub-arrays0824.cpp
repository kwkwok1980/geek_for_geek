// https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/1?page=1&status=attempted&sortBy=submissions

class Solution {
  public:
    int maxSum(std::vector<int>& values) {
        int N = values.size();
        int result = std::numeric_limits<int>::min();
        for (int i=0; i<N; ++i) {
            int j = i-1;
            int k = i+1;
            if (j > 0) {
                result = std::max(result, values[i] + values[j]);
            }
            if (k < N) {
                result = std::max(result, values[i] + values[k]);
            }
        }
        return result;
    }
};
