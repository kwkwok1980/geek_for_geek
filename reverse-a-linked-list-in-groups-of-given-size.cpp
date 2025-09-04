// https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
// Amazon, Microsoft, Goldman Sachs, Adobe

struct Solution {
  
    Node* reverseKGroup(Node* head, int k) {
        std::stack<Node*> nodes{};
        Node* group = nullptr;
        Node* first = nullptr;
        Node* top = nullptr;
        Node* cursor = head;
        while (cursor != nullptr) {
            for (int i=0; i<k; ++i) {
                nodes.push(cursor);
                cursor = cursor->next;
                if (cursor == nullptr) {
                    break;
                }
            }
            
            while (!nodes.empty()) {
                top = nodes.top();
                nodes.pop();
                if (first == nullptr) {
                    first = top;
                    group = top;
                } else {
                    group->next = top;
                    group = top;
                }
                
            }
            
            group->next = nullptr;
        }
        return first;
    }
    
};
