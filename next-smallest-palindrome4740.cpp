// https://www.geeksforgeeks.org/problems/next-smallest-palindrome4740/1

class Solution {
  public:
    std::vector<int> nextPalindrome(std::vector<int>& num) {
        int size = num.size();
        bool odd = (size % 2 != 0);
        int mid = odd ? (size / 2) : (size / 2 -1);
        int cursor1, cursor2;
        std::vector<int> results(size, 0);
        if (odd) {
            cursor1 = mid-1;
            cursor2 = mid+1; 
            results[mid] = num[mid];
        } else {
            cursor1 = mid;
            cursor2 = mid+1; 
        }
        
        int pass = 0;
        while (cursor1 >= 0) {
            int value1 = num[cursor1];
            int value2 = num[cursor2];
            if (pass == 0) {
                if (value1 > value2) {
                    pass = 1;
                } else if (value1 < value2) {
                    pass = -1;
                }
            }
            results[cursor1] = value1;
            results[cursor2] = value1;
            --cursor1;
            ++cursor2;
        }
        
        //return results;
        
        if (pass != 1) {
            if (odd) {
                if (results[mid] != 9) {
                    results[mid] = results[mid] + 1;
                    pass = 1;
                } else {
                    results[mid] = 0;
                    cursor1 = mid-1;
                    cursor2 = mid+1; 
                }
            } else {
                cursor1 = mid;
                cursor2 = mid+1; 
            }
            while (cursor1 >= 0) {
                if (results[cursor1] != 9) {
                    results[cursor1] = results[cursor1] + 1;
                    results[cursor2] = results[cursor2] + 1;
                    pass = 1;
                    break;
                } else {
                    results[cursor1] = 0;
                    results[cursor2] = 0;
                    --cursor1;
                    ++cursor2;
                }
            }
        }
        
        if (pass != 1) {
            results.push_back(1);
            results[0] = 1;
        }

        return results;
    }
};
