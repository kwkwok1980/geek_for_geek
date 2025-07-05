// https://www.geeksforgeeks.org/problems/subarrays-with-at-most-k-distinct-integers/1?page=1&status=attempted&sortBy=submissions

struct Solution {
    
    int countAtMostK(std::vector<int>& values, int K) {
        int N = values.size();
        int cursor = 0;
        int result = 0;
        std::unordered_map<int, int> values_map{};
        for (int i=0; i<N; ++i) {
            int value = values[i];
            while (cursor < N) {
                int cursor_value = values[cursor];
                if (values_map.find(cursor_value) != values_map.end()) {
                    ++values_map[cursor_value];
                    ++cursor;
                } else {
                    if (values_map.size() < K) {
                        ++values_map[cursor_value];    
                        ++cursor;
                    } else {
                        break;
                    }
                }
            }
            result = result + (cursor - i);
            --values_map[value];
            if (values_map[value] == 0){
                values_map.erase(value);
            }
        }
        return result;
    }
    
    int countAtMostK_bkp(std::vector<int>& values, int K) {
        int N = values.size();
        int result = 0;
        for (int i=0; i<N; ++i) {
            std::unordered_set<int> keys{};
            int sub_result = 0;
            for (int j=i; j<N; ++j) {
                int value = values[j];
                if (keys.size() < K) {
                    ++sub_result;
                    keys.emplace(value);
                } else {
                    if (keys.find(value) != keys.end()) {
                        ++sub_result;
                    } else {
                        break;
                    }
                }
            }
            result = result + sub_result;
        }
        return result;
    }
};
