class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<int> storeElement;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j <  matrix[0].size(); j++){
                storeElement.push_back(matrix[i][j]);
            }
        }
        int rowNumber = matrix.size() - 1;
        int colNumber = 0;
        int k = storeElement.size() - 1;
        while(k >= 0){
            matrix[rowNumber][colNumber] = storeElement[k];
            k--;
            if(rowNumber == 0){
                rowNumber = matrix.size() - 1;
                colNumber++;
            }else{
               rowNumber--;
            }

        }
    }
};

/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
//void rotate(vector<vector<int> > &matrix) {
//    reverse(matrix.begin(), matrix.end());
//    for (int i = 0; i < matrix.size(); ++i) {
//        for (int j = i + 1; j < matrix[i].size(); ++j)
//            swap(matrix[i][j], matrix[j][i]);
//    }
//}