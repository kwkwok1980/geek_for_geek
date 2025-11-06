// https://www.geeksforgeeks.org/problems/ways-to-tile-a-floor5836/1

class Solution {
  public:
    int numberOfWays(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int x1 = 1;
        int x2 = 2;
        int x3 = 0;
        for (int i=3; i<=n; ++i) {
            x3 = x2 + x1;
            x1 = x2;
            x2 = x3;
        }
        return x3;
    }
};
