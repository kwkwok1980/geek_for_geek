// https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1

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
#include <thread>
#include <source_location>
#include <ranges>
#include <map>

#include <boost/mp11.hpp>
#include <boost/core/demangle.hpp>

using namespace boost::mp11;

struct compare {
    bool operator()(const std::string& lhs, const std::string& rhs) const {
        int length1 = static_cast<int>(lhs.size());
        int length2 = static_cast<int>(rhs.size());
        int minLength = std::min(length1, length2);
        for (int i=0; i<minLength; ++i) {
            char c1 = lhs[i];
            char c2 = rhs[i];
            if (c1 != c2) {
                return c1 < c2;
            }
        }
        if (length1 > length2) {
            char c1 = lhs[0];
            char c2 = lhs[minLength + 1];
            return c1 >= c2;
        }
        else if (length1 < length2) {
            char c1 = rhs[0];
            char c2 = rhs[minLength + 1];
            return c1 < c2;
        }
        return true;
    }
};

struct compare2 {
    bool operator()(const std::string& lhs, const std::string& rhs) const {
        std::string s1 = lhs + rhs;
        std::string s2 = rhs + lhs;
        return s1 < s2;
    }
};


class Solution {
public:
    std::string findLargest(std::vector<int>& arr) {
        std::vector<std::string> values{};
        bool all_zero = true;
        for (int i : arr) {
            values.push_back(std::to_string(i));
            if (i != 0) all_zero = false;
        }
        if (all_zero) return "0";
        std::sort(std::begin(values), std::end(values), compare2{});
        std::reverse(std::begin(values), std::end(values));
        std::stringstream  ss{};
        for (const std::string& value : values) {
            ss << value;
        }
        return ss.str();
    }
};

int main() {
    {
        std::vector<int> values{3, 30, 34, 5, 9};
        Solution solution{};
        std::cout << solution.findLargest(values) << std::endl;
    }
    {
        std::vector<int> values{54, 546, 548, 60};
        Solution solution{};
        std::cout << solution.findLargest(values) << std::endl;
    }
    {

    }

}
