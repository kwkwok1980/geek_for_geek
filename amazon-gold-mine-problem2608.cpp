// https://www.geeksforgeeks.org/problems/gold-mine-problem2608/1

class Solution {
  public:
    int maxGold(vector<vector<int>>& mat) {
        int N = mat.size();
        std::vector<std::vector<int>> results(N, std::vector<int>(N, 0));
        for (int i=N-1; i>=0; --i) {
            for (int j=0; j<N; ++j) {
                int result = 0;
                if (i < N-1) {
                    if (j == 0) {
                        result = results[j][i+1];
                        result = std::max(result, results[j+1][i+1]);
                        
                    } else if (j == N-1) {
                        result = results[j][i+1];
                        result = std::max(result, results[j-1][i+1]);
                    } else {
                        result = results[j][i+1];
                        result = std::max(result, results[j-1][i+1]);
                        result = std::max(result, results[j+1][i+1]);
                    }
                }
                results[j][i] = result + mat[j][i];
                //std::cout << j << " " << i << " " << results[j][i] << std::endl;
            }
        }
        int result = 0;
        for (int i=0; i<N; ++i) {
            result = std::max(result, results[i][0]);
        }
        return result;
    }
};
