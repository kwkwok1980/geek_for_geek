// https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1?page=1&status=unsolved&sortBy=submissions
// VMWare, Amazon, Microsoft, Adobe, Google, Cisco
struct  Solution {
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int>& values, int k) {
        std::vector<int> results{};
        for (int i=0; i<k; ++i) {
            int value = values[i];
            results.push_back(value);
        }
        int N = values.size();
        std::sort(results.begin(), results.end());
        for (int i=k; i<N; ++i) {
            int value = values[i];
            if (value < results.back()) {
                auto it = std::lower_bound(results.begin(), results.end(), value);
                results.insert(it, value);
                results.pop_back();
            }
        }
        return results.back();
    }
};
