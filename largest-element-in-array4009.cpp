// https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1?page=1&company=Morgan%20Stanley&difficulty=Basic&status=unsolved&sortBy=submissions
// Oracle, Morgan Stanley

struct Solution {
  public:
    int largest(std::vector<int>& values) {
        int result = std::numeric_limits<int>::min();
        for (int value : values) {
            result = std::max(result, value);
        }
        return result;
    }
};
