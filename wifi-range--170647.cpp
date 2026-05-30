// https://www.geeksforgeeks.org/problems/wifi-range--170647/1

class Solution {
  public:
    bool wifiRange(string &s, int x) {
        int check = 0;
        for (char c : s) {
            if (c == '1') {
                check = x;
            } else {
                check = check - 1;
            }
            if (check < -x) {
                return false;
            }
        }
        return check >= 0;
    }
};
