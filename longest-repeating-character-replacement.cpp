// https://www.geeksforgeeks.org/problems/longest-repeating-character-replacement/1

struct Solution {
    int longestSubstr(std::string& s, int k) {
        int result = std::numeric_limits<int>::min();
        for (int i=0; i<26; ++i) {
            char c = static_cast<char>('A' + i);
            result = std::max(result, solution_impl(s, k, c));
        }
        return result;
    }

    int solution_impl(std::string s, int k, char c) {
        int x = 0 ;
        int y = 0;
        int z = k;
        int n = s.size();
        int result = std::numeric_limits<int>::min();
        while (y < n) {
            while (y < n) {
                char r = s[y];
                if (r == c) {
                    ++y;
                } else {
                    if (z > 0) {
                        --z;
                        ++y;
                    } else {
                        break;
                    }
                }
            }
            result = std::max(result, y-x);
            if (s[x] != c) {
                if (z < k) {
                    ++z;
                }
            }
            ++x;
        }
        return result;
    }
};
