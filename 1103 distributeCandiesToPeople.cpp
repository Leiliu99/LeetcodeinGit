class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        int remainCandies = candies;
        int index = 1;
        int indexValue = 1;
        int loopTime = 1;
        while(remainCandies - indexValue > 0){
            if(index > num_people){
                indexValue = loopTime * num_people + 1;
                index = 1;//reset the index to 1
                loopTime++;
            }
            res[index - 1] += indexValue;
            remainCandies = remainCandies - indexValue;
            //cout <<"index: " << index<< " and remain: "<<remainCandies<<endl;
            indexValue++;
            index++;
        }
        if(index > num_people){
            index = 1;//reset the index to 1
        }
        res[index - 1] += remainCandies;
        return res;

    }
};