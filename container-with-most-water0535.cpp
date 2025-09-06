// https://www.geeksforgeeks.org/problems/container-with-most-water0535/1
// Flipkart, Amazon, Google

struct Node {
    Node (int value, int index) :value(value), index(index){
    }
    int value;
    int index;
};

bool operator<(const Node& lhs, const Node& rhs) {
    if (lhs.value == rhs.value) {
        return lhs.index < rhs.index;
    } else{
        return lhs.value > rhs.value;
    }
}

struct Solution {
    
    int maxWater(std::vector<int>& values) {
        std::vector<Node> valuesList{};
        int N = values.size();
        for (int i=0; i<N; ++i) {
            int value = values[i];
            valuesList.emplace_back(value, i);
        }
        std::sort(valuesList.begin(), valuesList.end());
        int left = std::numeric_limits<int>::max();
        int right = std::numeric_limits<int>::min();
        int result = std::numeric_limits<int>::min();
        for (auto& node : valuesList) {
            left = std::min(left, node.index);
            right = std::max(right, node.index);
            result = std::max(result, node.value * (right - left));
        }
        return result;
    }
    
    
    int maxWater_bkp2(std::vector<int>& values) {
        std::set<Node> valuesSet{};
        int N = values.size();
        for (int i=0; i<N; ++i) {
            int value = values[i];
            valuesSet.emplace(value, i);
        }
        int left = std::numeric_limits<int>::max();
        int right = std::numeric_limits<int>::min();
        int result = std::numeric_limits<int>::min();
        for (auto& node : valuesSet) {
            left = std::min(left, node.index);
            right = std::max(right, node.index);
            result = std::max(result, node.value * (right - left));
        }
        return result;
    }
    
    int maxWater_bkp(std::vector<int>& values) {
        std::map<int, int, std::greater<int>> valuesMap{};
        int N = values.size();
        for (int i=0; i<N; ++i) {
            int value = values[i];
            valuesMap[value] = i;
        }
        int left = std::numeric_limits<int>::max();
        int right = std::numeric_limits<int>::min();
        int result = std::numeric_limits<int>::min();
        for (auto [value, i] : valuesMap) {
            left = std::min(left, i);
            right = std::max(right, i);
            result = std::max(result, value * (right - left));
        }
        return result;
    }
};
