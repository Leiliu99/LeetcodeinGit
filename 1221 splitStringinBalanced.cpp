class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0, cnt = 0;
    for (const auto& c : s) {
        cnt += c == 'L' ? 1 : -1;//very smart!!!!!!
        //the mistery of balance!
        if (cnt == 0) ++res;
    }
    return res;
    }
};