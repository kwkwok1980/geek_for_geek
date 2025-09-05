// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
// Amazon, Microsoft

/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
struct Solution {
    Node* segregate(Node* head) {
        Node* cursor = head;
        int count_0 = 0;
        int count_1 = 0;
        int count_2 = 0;
        while (cursor != nullptr) {
            if (cursor->data == 0) {
                ++count_0;
            } else if (cursor->data == 1) {
                ++count_1;
            } else {
                ++count_2;
            }
            cursor = cursor->next;
        }
        cursor = head;
        while (cursor != nullptr) {
            if (count_0 > 0) {
                cursor->data = 0;
                --count_0;
            } else if (count_1 > 0) {
                cursor->data = 1;
                --count_1;
            } else {
                cursor->data = 2;
                --count_2;
            }
            cursor = cursor->next;
        }
        return head;
    }
};
