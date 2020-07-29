class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> countTable(1001, 0);//count table!!!!
        for(int i = 0; i <  arr1.size(); i++){
            countTable[arr1[i]]++;//store all the values from arr1 in the count table
        }
        vector<int> res;
        for(int k = 0; k < arr2.size(); k++){
            while(countTable[arr2[k]] > 0){
                res.push_back(arr2[k]);
                countTable[arr2[k]]--;//push the values and also the duplicated one where arr2 has in result
                //with the order of arr2
            }
        }
        for(int j = 0; j < countTable.size(); j++){
            if(countTable[j] == 0) continue;
            while(countTable[j] > 0){
                res.push_back(j);
                countTable[j]--;//the rest of it can be pushed based on their order small to big
                //by for loop the entire counttable remaining value
            }
        }
        return res;

    }
};