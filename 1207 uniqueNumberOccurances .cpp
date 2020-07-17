class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int occur = 1;
        int preNumber = arr[0];
        vector<int> occurList;
        for(int i = 1; i < arr.size(); i++){
            if(preNumber == arr[i]){
                occur++;
            }else{
                if(find(occurList.begin(), occurList.end(), occur) != occurList.end()){
                    return false;
                }
                occurList.push_back(occur);
                occur = 1;
                preNumber = arr[i];
            }
        }
        if(find(occurList.begin(), occurList.end(), occur) != occurList.end()){
                    return false;
        }
        return true;

    }
};
bool uniqueOccurrences(vector<int>& arr) {
         short m[2001] = {};
        for (auto n : arr) ++m[n + 1000];
        sort(begin(m), end(m));//sort let occurance from small to big
         for (auto i = 1; i < 2001; ++i)
            if (m[i] && m[i] == m[i - 1]) return false; //this number occurance is not zero and is equal to its neighbour
         return true;

}