// https://www.geeksforgeeks.org/problems/vertical-sum/1
/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
struct Solution {
    
    std::map<int, int> resultMap{};
    vector<int> verticalSum(Node* root) {
        impl(root, 0);
        std::vector<int> resultList{};
        for (auto [k, v] : resultMap) {
            resultList.push_back(v);
        }
        return resultList;
    }
    
    void impl(Node* node, int column) {
        resultMap[column] = resultMap[column] + node->data;
        if (node->left != nullptr) {
            impl(node->left, column - 1);
        }
        if (node->right != nullptr) {
            impl(node->right, column + 1);
        }
    }
};
