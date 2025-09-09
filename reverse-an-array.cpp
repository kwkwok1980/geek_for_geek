// https://www.geeksforgeeks.org/problems/reverse-an-array/1?page=1&company=Morgan%20Stanley&difficulty=Easy&status=unsolved&sortBy=submissions
// Bloomberg, Gooogle, Morgan Stanley Amazon, Microsoft, Apple

class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        int N = arr.size();
        for (int i=0; i<N/2; ++i) {
            std::swap(arr[i], arr[N-1-i]);
        }
    }
};
