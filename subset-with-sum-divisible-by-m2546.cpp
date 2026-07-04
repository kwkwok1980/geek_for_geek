// https://www.geeksforgeeks.org/problems/subset-with-sum-divisible-by-m2546/1

struct Solution {
    std::vector<std::vector<int>> results{};
  
  
    bool divisibleByK(vector<int>& arr, int k) {
        results = std::vector<std::vector<int>>(1000+1, std::vector<int>(1000+1, 0));
        divisibleByKImpl(arr, k, 0 , 0);
    }
    
    bool divisibleByKImpl(vector<int>& arr, int k, int i, int sum) {
        int sum1 = sum + arr[i];
        int sum2 = sum ;
        if ((sum1 % k == 0) && (sum1 != 0)) return true;
        if ((sum2 % k == 0) && (sum2 != 0)) return true;
        i = i + 1;
        if (i < arr.size()) {
            if (results[i][sum1 % k] == -1) {
                return false;
            }
            if (results[i][sum2 % k] == -1) {
                return false;
            }
            if (divisibleByKImpl(arr, k, i, sum1)) {
                return true;
            } else {
                results[i][sum1 % k] = -1;
            }
            if (divisibleByKImpl(arr, k, i, sum2)) {
                return true;
            } else {
                results[i][sum2 % k] = -1;
            }
        }
        return false;
    }
};
