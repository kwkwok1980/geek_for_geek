// https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1?page=1&company=Morgan%20Stanley&difficulty=Easy&status=unsolved&sortBy=submissions

class Solution {
  public:
    int missingNum(vector<int>& arr) {
        int N = arr.size();
        std::uint64_t S = N + 1;
        std::uint64_t sum = (S + 1) * S / 2;
        for (int i=0; i<N; ++i) {
            sum = sum - arr[i];
        }
        return sum;
    }
};
