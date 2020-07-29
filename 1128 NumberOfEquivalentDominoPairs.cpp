class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> dict;
        int count = 0;
        for (vector<int> d: dominoes) {
            int a = (d[0] << 4) | d[1], b = (d[1] << 4) | d[0];//if vector is [1,2] a=12,b=21
            count += (a == b ? 0 : dict[b]) + dict[a]++;
            //
        }
        return count;
    }
};