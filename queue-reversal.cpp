// https://www.geeksforgeeks.org/problems/queue-reversal/1
// Amazon


class Solution {
public:
    void reverseQueue(std::queue<int> &q) {
        std::stack<int> s;
        while (!q.empty()) {
            s.push(q.front());
            q.pop();
        }
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }
    }
};
