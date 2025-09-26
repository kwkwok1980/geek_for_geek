// https://www.geeksforgeeks.org/problems/max-rectangle/1
// Amazon, Microsoft, Google

class Solution {
public:
    int maxArea(std::vector<std::vector<int>>& mat) {
        int N = mat.size();
        int M = mat[0].size();
        
        std::vector<std::vector<int>> results(N, std::vector<int>(M, 0));
        for (int m=0; m<M; ++m) {
            int result = 0;
            for (int n=0; n<N; ++n) {
                int value = mat[n][m];
                if (value == 1) {
                    ++result;
                } else {
                    result = 0;
                }
                results[n][m] = result;
            }
        }
        
        int max = 0;
        for (int n=N-1; n>=0; --n) {
            for (int m=0; m<M; ++m) {
                int value = mat[n][m];
                if (value == 1) {
                    int height = results[n][m];
                    int width = 1;
                    max = std::max(max, height * width);
                    for (int k=m+1; k<M; ++k){
                        int value_tmp = mat[n][k];
                        if (value_tmp == 1) {
                            int height_tmp =results[n][k];
                            height = std::min(height, height_tmp);
                            width = width + 1;
                            max = std::max(max, height * width);
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        return max;
    }
};
