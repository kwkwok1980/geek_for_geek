// https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1

class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        std::deque<int> nodes{};
        int n = arr.size();
        int i = 0;
        nodes.push_back(arr[i++]);
        while (i < n) {
            int node = nodes.front();
            nodes.pop_front();
            if (i < n) {
                int left = arr[i++];
                if (node < left) {
                    return false;
                }
                nodes.push_back(left);
            }
            if (i < n) {
                int right = arr[i++];
                if (node < right) {
                    return false;
                }
                nodes.push_back(right);
            }
        }
        return true;
    }
};
