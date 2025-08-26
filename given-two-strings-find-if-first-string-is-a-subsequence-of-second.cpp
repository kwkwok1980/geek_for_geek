// https://www.geeksforgeeks.org/problems/given-two-strings-find-if-first-string-is-a-subsequence-of-second/1

struct Solution {
    bool isSubSeq(std::string& s1, std::string& s2) {
        std::size_t cursor1 = 0;
        std::size_t cursor2 = 0;
        std::size_t N1 = s1.size();
        std::size_t N2 = s2.size();
        
        while (cursor1 < N1) {
            bool found = false;
            char c1 = s1[cursor1];
            while (cursor2 < N2) {
                char c2 = s2[cursor2++];
                found = (c1 == c2);
                if (found) {
                    break;
                }
            }
            if (!found) return false;
            ++cursor1;
        }
        
        return true;
    }
};
