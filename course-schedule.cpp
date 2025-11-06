// https://www.geeksforgeeks.org/problems/course-schedule/1
// Google

class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        std::vector<int> counts(n, 0);
        std::unordered_map<int, std::vector<int>> prerequisiteMap{};
        for (const std::vector<int>& prerequisite : prerequisites) {
            int x = prerequisite[0];
            int y = prerequisite[1];
            ++counts[x];
            prerequisiteMap[y].push_back(x);
        }
        
        std::list<int> events{};
        for (int y=0; y<n; ++y) {
            if (counts[y] == 0) {
                events.push_back(y);
            }
        }
        
        std::vector<int> results{};
        while (!events.empty()) {
            int y = events.front();
            events.pop_front();
            results.push_back(y);
            for (int x : prerequisiteMap[y]) {
                --counts[x];
                if (counts[x] == 0){
                    events.push_back(x);
                }
            }
        }
        return results;
    }
};
