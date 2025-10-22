// https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        int cursor = 0;
        std::set<int> values{};
        int N = arr.size();
        for (int i=0; i<=k; ++i) {
            values.emplace(arr[i]);
        }
        for (int i=k+1; i<N; ++i) {
            values.emplace(arr[i]);
            auto it = values.begin();
            arr[cursor++] = *it;
            values.erase(it);
        }
        while (!values.empty()) {
            auto it = values.begin();
            arr[cursor++] = *it;
            values.erase(it);
        }
    }
    
    void nearlySorted_2(vector<int>& arr, int k) {
        int N = arr.size();
        for (int i=0; i<N; ++i) {
            int M = std::min(N, i+k+1);
            for (int j=M-1; j>i; --j) {
                if (arr[j] < arr[j-1]) {
                    std::swap(arr[j], arr[j-1]);
                }
            }
        }
    }
    
    void nearlySorted_3(vector<int>& arr, int k) {
        int N = arr.size();
        std::sort(arr.begin(), arr.begin() + k + 1);
        for (int i=k+1; i<N; ++i) {
            int j = i;
            while (j > 0) {
                if (arr[j] < arr[j-1]) {
                    std::swap(arr[j], arr[j-1]);
                } else {
                    break;
                }
                --j;
            }
        }
    }
};
