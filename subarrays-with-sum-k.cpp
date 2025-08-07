// https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/1
// Microsoft
struct Solution {
    int cntSubarrays(std::vector<int>& values, int k) {
        int N = values.size();
        std::vector<int> results(N, 0);
        results[0] = values[0];
        for (int i=1; i<N; ++i) {
            results[i] = results[i-1] + values[i];
        }
        int count = 0;
        std::unordered_map<int, int> results_map{};
        for (int i=0; i<N; ++i) {
            int result = results[i];
            if (result == k) {
                count = count + 1;
                count = count + results_map[0];
            } else {
                int opp = result - k;
                count = count + results_map[opp];
            }
            ++results_map[result];
        }
        return count;
    }
   
};
