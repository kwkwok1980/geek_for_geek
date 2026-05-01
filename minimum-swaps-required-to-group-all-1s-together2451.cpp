// https://www.geeksforgeeks.org/problems/minimum-swaps-required-to-group-all-1s-together2451/1

class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        int k = 0;
        for (int i=0; i<n; ++i) {
            if (arr[i] == 1) {
                ++k;
            }
        }
        if (k == 0) {
            return -1;
        }
        int c = 0;
        for (int i=0; i<k; ++i) {
            if (arr[i] == 1) {
                ++c;
            }
        }
        int result = std::numeric_limits<int>::max();
        for (int i=0; i+k<=n; ++i) {
            result = std::min(k-c, result);
            if (arr[i] == 1) {
                --c;
            }
            if (i+k < n) {
                if (arr[i+k] == 1) {
                    ++c;
                }
            }
        }
        return result;
        
    }
};
