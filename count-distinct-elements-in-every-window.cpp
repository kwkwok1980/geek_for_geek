// https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1

class Solution {
  public:
    std::vector<int> countDistinct(std::vector<int> &arr, int k) {
        std::vector<int> results{};
        std::unordered_map<int, int> counts{};
        int result = 0;
        int count = 0;
        int value = 0;
        for (int i=0; i<k; ++i) {
            value = arr[i];
            if (++counts[value] == 1) {
                ++result;
            }
        }
        results.push_back(result);
        
        for (int i=k; i<arr.size(); ++i) {
            value = arr[i-k];
            if (--counts[value] == 0){
                --result;
            }
            
            value = arr[i];
            if (++counts[value] == 1) {
                ++result;
            }
            
            results.push_back(result);
        }
        return results;
    }
};
