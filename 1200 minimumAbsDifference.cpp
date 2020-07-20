class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        int min_diff = INT_MAX;
        // find min difference
         for (int i = 0; i < arr.size() - 1; ++i) {
             min_diff = min(arr[i + 1] - arr[i], min_diff);
         }

        // form a list of pairs with min difference, ascending
        for (int i = 0; i < arr.size() - 1; ++i) {
            if (arr[i + 1] - arr[i] == min_diff)
             result.push_back({arr[i], arr[i + 1]});
         }
        return result;

    }
};
//
// vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
//        sort(arr.begin(),arr.end());
//        vector<vector<int>> res;
//        vector<int> candidates;
//        int Difference = arr[arr.size() - 1] - arr[arr.size() - 2];
//        //cout<< Difference <<endl;
//        candidates.push_back(arr.size() - 2);
//        for(int i = (arr.size() - 2); i > 0; i--){
//            // cout<<"i: "<<i<<" Difference: "<<Difference<<endl;
//            if(Difference == arr[i] - arr[i - 1]){
//                //cout<<"candidates i: "<<i-1<<endl;
//                candidates.push_back(i - 1);
//            }else if(Difference > arr[i] - arr[i - 1]){
//                cout<<"here"<<endl;
//                candidates.clear();
//                Difference = arr[i] - arr[i - 1];
//                candidates.push_back(i - 1);
//            }
//        }
//
//        vector<int> temp;
//        for(int k = candidates.size()-1; k >= 0; k--){
//            temp = {arr[candidates[k]], arr[candidates[k]+1]};
//            res.push_back(temp);
//        }
//        return res;
//
//    }
