// https://www.geeksforgeeks.org/problems/assign-mice-holes3053/1
struct Solution {
    
    int assignHole(std::vector<int>& mices, std::vector<int>& holes) {
        std::sort(mices.begin(), mices.end());
        std::sort(holes.begin(), holes.end());
        int N = mices.size();
        int result = std::numeric_limits<int>::min();
        for(int i=0; i<N; ++i){
            result = std::max(result, std::abs(mices[i] - holes[i]));
        }
        return result;
    }
};
