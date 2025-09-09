// https://www.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1?page=1&company=Morgan%20Stanley&difficulty=Easy&sortBy=submissions
// Morgan Stanley, Amazon, Microsoft, Adobe
/*
class Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */

class Solution {
  public:
    int getMiddle(Node* head) {
        int N = 0;
        Node* cursor = head;
        while (cursor != nullptr) {
            ++N;
            cursor = cursor->next;
        }
        cursor = head;
        N = N/2 + 1;
        while (N > 1) {
            cursor = cursor->next;
            --N;
        }
        return cursor->data;
    }
};
