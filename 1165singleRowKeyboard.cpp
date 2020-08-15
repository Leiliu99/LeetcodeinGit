class Solution {
public:
    int calculateTime(string keyboard, string word) {
        vector<int> characterPosition(26, 0);
        for(int i = 0; i < keyboard.size(); i++){
            int character = keyboard[i];
            int position = character - 97;
            characterPosition[position] = i;
        }
        int res = 0;
        int prePosition = 0;
        for(int k = 0; k < word.size(); k++){
            int character = word[k];
            int position = character - 97;
            if(k == 0){
                res += characterPosition[position];
                prePosition = characterPosition[position];
                //cout<<"k: "<<k<<"and: "<<prePosition<<endl;
            }else{
                int currentStepNeed = abs(characterPosition[position] - prePosition);
                res += currentStepNeed;
                prePosition = characterPosition[position];
                //cout<<"k: "<<k<<"and: "<<currentStepNeed<<endl;
            }

        }
        return res;
    }
};