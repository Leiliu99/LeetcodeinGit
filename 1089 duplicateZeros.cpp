class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size(), j = n + count(arr.begin(), arr.end(), 0);
        //cout<<count(arr.begin(), arr.end(), 0)<<endl;
        for (int i = n - 1; i >= 0; --i) {
            if (--j < n)
                arr[j] = arr[i];
            if (arr[i] == 0 && --j < n)
                arr[j] = 0;
            // cout<<"i: "<<i<<" and j: "<<j<<" is ";
            // for(int k = 0; k < arr.size(); k++){
            //     cout<<arr[k];
            // }
            // cout<<endl;
        }
//Very smart: modify the same array!!
    }
};