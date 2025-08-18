// https://www.geeksforgeeks.org/problems/find-h-index--165609/1

struct Solution {
    int hIndex(std::vector<int>& citations) {
        int N = 1000000;

        std::vector<int> paper_counts(N+1, 0);
        for (int citation : citations) {
            ++paper_counts[citation];
        }
        
        int paper_count = 0;
        for (int n=N; n>=0; --n) {
            paper_count = paper_count + paper_counts[n];
            if (paper_count >= n) {
                return n;
            }
        }
        return 0;
    }
};
