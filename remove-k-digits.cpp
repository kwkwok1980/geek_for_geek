// https://www.geeksforgeeks.org/problems/remove-k-digits/1

class Solution {
  public:
    std::string removeKdig(std::string &s, int k) {
        int target = s.length() - k;
        std::list<char> values{};
        for (char c : s) {
            values.push_back(c);
        }
        auto it = values.begin();
        while (true) {
            if (k == 0) {
                break;
            }
            auto it2 = std::next(it);
            if (it2 == values.end()) {
                break;
            }
            if (*it > *it2) {
                it = values.erase(it);
                --k;
                it = it == values.begin() ? it : std::prev(it);
            } else {
                ++it;
            }
        }
        std::stringstream ss{};
        it = values.begin();
        for (int i=0; i<target; ++i) {
            ss << *it++;            
        }
        std::string result =ss.str();
        int found = result.find_first_not_of('0');
        if (found != std::string::npos) {
            result = result.substr(found);
        } else {
            result = "0";
        }
        return result;
    }
  
  
    std::string removeKdig_bkp_2(std::string &s, int k) {
        int len = s.length() - k;
        int cursor = 0;
        while (true) {
            if (k == 0) {
                break;
            }
            if (cursor == s.length()-1) {
                break;
            }
            
            if (s[cursor] > s[cursor+1]) {
                s.erase(cursor, 1);
                --k;
                cursor = std::max(--cursor, 0);
            } else {
                ++cursor;
            }
        }
        if (s.length() > len) {
            s = s.substr(0, len);
        }
        int found = s.find_first_not_of('0');
        if (found != std::string::npos) {
            s = s.substr(found);
        } else {
            s = "0";
        }
        return s;
    }
  
    std::string removeKdig_bkp_1(std::string &s, int k) {
        int len = s.length();
        impl(s, k);
        if (s.length() > (len - k)) {
            s = s.substr(0, (len - k));
        }
        int found = s.find_first_not_of('0');
        if (found != std::string::npos) {
            s = s.substr(found);
        } else {
            s = "0";
        }
        return s;
    }
    
    void impl(std::string& s, int k) {
        if (k == 0) {
            return;
        }
        int len = s.size();
        for (int i=0; i<len-1; ++i) {
            if (s[i] > s[i+1]) {
                s.erase(i, 1);
                return impl(s, k-1);
            }
        }
    }
    
};
