// https://www.geeksforgeeks.org/problems/decode-the-string2444/1
// Microsoft, Facebook
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <algorithm>
#include <stack>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <cmath>
#include <sstream>

struct Solution {
    std::string decodedString(std::string& values) {
        std::stack<char> values_stack{};
        char top;
        for (char value : values) {
            if (value != ']') {
                values_stack.push(value);
            } else {
                std::stringstream ss1{};
                std::stringstream ss2{};
                while (true) {
                    top = values_stack.top();
                    values_stack.pop();
                    if (top != '[') {
                        ss1 << top;
                    } else {
                        while (true) {
                            if (!values_stack.empty() && values_stack.top() >= '0' && values_stack.top() <= '9') {
                                top = values_stack.top();
                                values_stack.pop();
                                ss2 << top;
                            } else {
                                std::string s1 = ss1.str();
                                std::reverse(s1.begin(), s1.end());
                                std::string s2 = ss2.str();
                                std::reverse(s2.begin(), s2.end());
                                int n = atoi(s2.c_str());
                                for (int i=0; i<n; ++i) {
                                    for (char c : s1) {
                                        values_stack.push(c);
                                    }
                                }
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }
        std::stringstream ss_result{};
        while (!values_stack.empty()) {
            ss_result << values_stack.top();
            values_stack.pop();
        }
        std::string s_result = ss_result.str();
        std::reverse(s_result.begin(), s_result.end());
        return s_result;
    }
};

int main() {

    Solution solution{};
    std::string s = "3[b2[ca]]";
    std::cout << solution.decodedString(s) << std::endl;

}

