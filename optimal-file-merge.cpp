// https://www.geeksforgeeks.org/problems/optimal-file-merge/1

struct Solution {
    int minComputation(std::vector<int>& files) {
        int N = files.size();
        if (N == 1) {
            return 0;
        }
        
        int result = 0;
        std::map<int, int> filesMap{};
        for (int value : files) {
            filesMap[value] =  filesMap[value] + 1;
        }
        
        int n = N;
        while (true) {
            if (n == 2) {
                int cost1 = filesMap.begin()->first;
                int count1 = filesMap.begin()->second;
                if (count1 > 1) {
                    int cost2 = cost1;
                    int cost = cost1 + cost2;
                    result = result + cost;
                } else {
                    filesMap.erase(cost1);
                    int cost2 = filesMap.begin()->first;
                    int cost = cost1 + cost2;
                    result = result + cost;
                }
                break;
            } else {
                int cost1 = filesMap.begin()->first;
                int count1 = filesMap.begin()->second;
                if (count1 > 1) {
                    int cost2 = cost1;
                    int cost = cost1 + cost2;
                    result = result + cost;
                    count1 = count1 - 2;
                    if (count1 == 0) {
                        filesMap.erase(cost1);
                    } else {
                        filesMap[cost1] = count1;
                    }
                    filesMap[cost] = filesMap[cost] + 1;
                } else {
                    filesMap.erase(cost1);
                    int cost2 = filesMap.begin()->first;
                    int count2 = filesMap.begin()->second;
                    int cost = cost1 + cost2;
                    result = result + cost;
                    count2 = count2  - 1;
                    if (count2 == 0) {
                        filesMap.erase(cost2);
                    } else {
                        filesMap[cost2] = count2;
                    }
                    filesMap[cost] = filesMap[cost] + 1;
                }
                
            }
            --n;
        }
        return result;

    }
};

