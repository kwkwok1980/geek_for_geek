// https://www.geeksforgeeks.org/problems/construct-an-array-from-its-pair-sum-array/1

class Solution {
  public:
    vector<int> constructArr(vector<int>& arr) {
        std::vector<int> results{};
        int K = arr.size();
        if (K == 1) {
            results.push_back(1);
            results.push_back(arr[0] - 1);
            return results;
        }
        int N = 0;
        for (int i=2; i<=1000; ++i) {
            if (i*(i-1) == 2*K) {
                N = i;
                break;
            }
        }
        int n = (arr[0] + arr[1] - arr[N-1])/2;
        //std::cout << arr[0] << std::endl;
        //std::cout << arr[1] << std::endl;
        //std::cout << arr[N-1] << std::endl;
        //std::cout << n << std::endl;
        results.push_back(n);
        for (int i=0; i<N-1; ++i) {
            results.push_back(arr[i] - n);
        }
        return results;
    }
};
