class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int numberPoints = indices.size();
        //int position = indices[0].size();
        int count = 0;
        vector<vector<int> > res( n , vector<int> (m));
        for(int i = 0; i < numberPoints; i++){
            int row = indices[i][0];
            int col = indices[i][1];
            for(int a = 0; a < m; a ++){
                if(res[row][a] % 2 == 0){
                    count++;
                }else{
                    count--;
                }
                res[row][a]++;
            }
            for(int b = 0; b < n; b++){
                if(res[b][col] % 2 == 0){
                    count++;
                }else{
                    count--;
                }
                res[b][col]++;
            }
        }
        return count;
    }
};
//vector<bool> N(n, false);
//        vector<bool> M(m, false);
//
//        for(int i=0; i<indices.size(); i++) {
//            N[indices[i][0]] = N[indices[i][0]]^true;
//            M[indices[i][1]] = M[indices[i][1]]^true;
//        }
//
//        int r = 0;
//        int c = 0;
//
//        for(int i=0; i<n; i++) {
//            if(N[i])
//                r++;
//        }
//
//        for(int j=0; j<m; j++) {
//            if(M[j])
//                c++;
//        }
//
//        return  r*m + c*n - 2*r*c;



//
//int odds = 0;
//        vector<bool> rows(n, false);
//        vector<bool> cols(m, false);
//        for(auto vec : indices) {
//            rows[vec[0]] = !rows[vec[0]];
//            cols[vec[1]] = !cols[vec[1]];
//        }
//        for(int i = 0; i < n; i ++)
//            for(int j = 0; j < m; j ++)
//                if(rows[i] ^ cols[j]) odds ++; if col contribution and row contribution is not the same amount that means it's an odd
//        return odds;
