// https://www.geeksforgeeks.org/problems/tywins-war-strategy0527/1

struct Solution {
    int minSoldiers(std::vector<int>& arr, int k) {
        int N = arr.size();
        std::vector<int> results(N, 0);
        for (int i=0; i<N; ++i) {
            int result = arr[i] % k;
            if (result != 0) {
                result = k - result; 
            }
            results[i] = result;
        }
        std::sort(results.begin(), results.end());
        int sum = 0;
        for (int i=0; i<(N+1)/2; ++i) {
            sum = sum + results[i];
        }
        return sum;
    }
};
