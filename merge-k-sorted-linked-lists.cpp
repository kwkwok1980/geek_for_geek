// https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1
// VMWare, Amazon, Microsoft, Oracle

/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

bool compare_node(const Node* lhs, const Node* rhs) {
    return lhs->data < rhs->data; 
}

struct Solution {
    Node* mergeKLists(std::vector<Node*>& values) {
        int N = values.size();
        std::vector<Node*> resultList{};
        for (int i=0; i<N; ++i) {
            Node* node = values[i];
            auto it = std::lower_bound(resultList.begin(), resultList.end(), node, compare_node);
            resultList.insert(it, node);
        }
        Node* first = nullptr;
        Node* cursor = nullptr;
        Node* front = nullptr;
        Node* next = nullptr;
        while (!resultList.empty()) {
            front = resultList.front();
            next = front->next;
            if (first == nullptr) {
                first = front;
                cursor = front;
            } else {
                cursor->next = front;
                cursor = front;
            }
            resultList.erase(resultList.begin());
            if (next != nullptr) {
                auto it = std::lower_bound(resultList.begin(), resultList.end(), next, compare_node);
                resultList.insert(it, next);
            }
        }
        return first;
    }
};
