// https://www.geeksforgeeks.org/problems/palindrome-string0817/1?page=1&company=Morgan%20Stanley&difficulty=Easy&status=unsolved&sortBy=submissions
// Morgan Stanley, Amazon, D-E-Shaw, Cisco, Facebook

class Solution {
  public:
    bool isPalindrome(std::string& s) {
        int N = s.size();
        int left = 0;
        int right = N-1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            } else {
                ++left;
                --right;
            }
        }
        return true;
    }
};
