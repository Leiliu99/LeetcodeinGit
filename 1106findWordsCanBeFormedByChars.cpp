class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res = 0;
        vector<int> countTable(26, 0);
        for(int k = 0; k < chars.length(); k++){
            int charNumber = int(chars[k]);
            int index = charNumber - 97;
            countTable[index]++;
        }
        for(int i = 0; i < words.size(); i++){
            bool canBeFormed = true;
            vector<int> coutTableRef = countTable;
            for(int j = 0; j < words[i].length(); j++){
                int indexTest = words[i][j] - 97;
                if(coutTableRef[indexTest] == 0){
                    canBeFormed = false;
                    break;
                }else{
                   coutTableRef[indexTest]--;
                }
            }
            if(canBeFormed){
                res += words[i].length();
            }
        }
        return res;
    }
};

//int countCharacters(vector<string>& words, string chars, int res = 0) {
//  vector<int> cnt(26);
//  for (auto ch : chars) ++cnt[ch - 'a'];
//  for (auto w : words) {
//    vector<int> cnt1 = cnt;
//    bool match = true;
//    for (auto ch : w) {
//      if (--cnt1[ch - 'a'] < 0) {
//        match = false;
//        break;
//      }
//    }
//    if (match) res += w.size();
//  }
//  return res;
//}