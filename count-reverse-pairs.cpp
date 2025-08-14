// https://www.geeksforgeeks.org/problems/count-reverse-pairs/1
// Bloomberg, Amazon, Microsoft, Adobe Google, Uber

struct Node {
    int index = 0;
    int value = 0;
};


bool operator<(const Node& lhs, const Node& rhs) {
    if (lhs.value == rhs.value) {
        return lhs.index < rhs.index;
    } else {
        return lhs.value < rhs.value;
    }
}

struct Solution {
    int countRevPairs(std::vector<int>& values) {
        int N = values.size();
        std::vector<Node> nodes{};
        int count = 0;
        for (int i=N-1; i>=0; --i) {
            int value = values[i];
            Node node1{i, value};
            auto it1 = std::lower_bound(nodes.begin(), nodes.end(), node1);
            int distance = std::distance(nodes.begin(), it1);
            count = count + distance;
            //std::cout << "cp1: " << value << " " << distance << std::endl;        
            Node node2{i, values[i] * 2};
            auto it2 = std::lower_bound(nodes.begin(), nodes.end(), node2);
            nodes.insert(it2, node2);    
        }
        
        return count;
        
    }
};
