class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> queriesFrequency;
        vector<int> wordsFrequency;
        vector<int> res;
        for(int i = 0; i < queries.size(); i++){

            int frequencyQuery = 1;
            char minCharQuery = queries[i][0];
            for(int k = 1; k < queries[i].length(); k++){
                if(queries[i][k] < minCharQuery){
                    frequencyQuery = 1;
                    minCharQuery = queries[i][k];
                }else if(queries[i][k] == minCharQuery){
                    frequencyQuery++;
                }
            }
            queriesFrequency.push_back(frequencyQuery);
        }

        for(int j = 0; j < words.size(); j++){
            int frequencyWord = 1;
            char minCharWord = words[j][0];
             for(int k = 1; k < words[j].length(); k++){
                if(words[j][k] < minCharWord){
                    frequencyWord = 1;
                    minCharWord = words[j][k];
                }else if(words[j][k] == minCharWord){
                    frequencyWord++;
                }
            }
            wordsFrequency.push_back(frequencyWord);
        }
        sort(wordsFrequency.begin(), wordsFrequency.end());
        for(int i = 0; i < queriesFrequency.size(); i++){
            int numberPerRun = 0;
            int frequencyPerRun =  queriesFrequency[i];
            for(int k = wordsFrequency.size() - 1; k >= 0; k--){
                if(wordsFrequency[k] <= frequencyPerRun){
                    break;
                }else{
                    numberPerRun++;
                }
            }
            res.push_back(numberPerRun);
        }
        return res;

    }
};