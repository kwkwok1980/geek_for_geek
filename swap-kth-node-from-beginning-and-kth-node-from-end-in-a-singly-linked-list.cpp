/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

// https://www.geeksforgeeks.org/problems/swap-kth-node-from-beginning-and-kth-node-from-end-in-a-singly-linked-list/1

struct Solution {
    Node* swapKth(Node* head, int k) {
        Node* cursor = head;
        int N = 0;
        Node* first = nullptr;
        Node* second = nullptr;
        while (cursor != nullptr) {
            ++N;
            if (N == k) {
                first = cursor;
            }
            cursor = cursor->next;
        }
        
        if (N < k) {
            return head;
        }
        
        cursor = head;
        while (cursor != nullptr) {
            if (N == k) {
                second = cursor;
                break;
            }
            --N;
            cursor = cursor->next;
        }
        std::swap(first->data, second->data);
        return head;
    }
};
