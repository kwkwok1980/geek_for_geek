// https://www.geeksforgeeks.org/problems/delete-alternate-nodes/1?page=1&company=Morgan%20Stanley&difficulty=Easy&status=unsolved&sortBy=submissions
// Morgan Stanley

/*
Structure of the node of the binary tree
struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        int data = x;
        next = NULL;
    }
};
*/
// Complete this function
class Solution {
  public:
    void deleteAlt(struct Node *head) {
        Node* cursor = head;
        while (cursor != nullptr) {
            if (cursor->next != nullptr) {
                cursor->next = cursor->next->next;
            }
            cursor = cursor->next;
        }
    }
};
