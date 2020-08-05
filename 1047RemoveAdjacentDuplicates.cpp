class Solution {
public:
    string removeDuplicates(string S) {
        int i = 0, n = S.length();
        //i new pointer for result
        //j pointer to traverse the original input
        for (int j = 0; j < n; ++j, ++i) {
            S[i] = S[j];
            if (i > 0 && S[i - 1] == S[i]) // count = 2
                i -= 2;
        }
        return S.substr(0, i);

    }
};