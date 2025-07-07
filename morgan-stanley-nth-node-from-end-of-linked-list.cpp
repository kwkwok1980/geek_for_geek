// https://www.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1?page=1&company=Morgan%20Stanley&difficulty=Easy&status=unsolved&sortBy=submissions

class Solution {
  public:
    int getKthFromLast(Node *head, int k) {
        Node* cursor = head;
        int N = 0;
        while (cursor != nullptr) {
            ++N;
            cursor = cursor->next;
        }
        int S = N - k;
        if (S >= 0) {
            Node* cursor = head;    
            for (int i=0; i<S; ++i) {
                cursor = cursor->next;
            }
            return cursor->data;
            
        } else {
            return -1;
        }
        
        // Your code here
        
    }
};
