class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int m=-1;
        for(int i=arr.size()-1;i>=0;i--) {
            int cur=arr[i];
            arr[i]=m;
            m=max(m, cur); //current compared to the maxium number so far from the right to current location
        }
        return arr;
    }
};