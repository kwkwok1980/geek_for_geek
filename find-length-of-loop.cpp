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

// https://www.geeksforgeeks.org/problems/find-length-of-loop/1
// Amazon, Adobe, Qualcomm

struct Solution {
    int lengthOfLoop(Node *head) {
        Node* cursor1 = head;
        Node* cursor2 = head;
        
        do {
            cursor1 = cursor1->next;
            cursor2 = cursor2->next;
            if (cursor2 != nullptr) {
                cursor2 = cursor2->next;
            } else {
                return 0;
            }
            if (cursor1 == cursor2) {
                break;
            }
        } while (cursor1 != nullptr && cursor2 != nullptr);
        
        if (cursor1 != cursor2) {
            return 0;
        }

        int result = 0;
        do {
            ++result;
            cursor2 = cursor2->next;
        } while (cursor1 != cursor2);
        return result;
    }
};
