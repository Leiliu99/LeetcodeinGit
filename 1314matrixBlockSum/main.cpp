#include <iostream>
#include <vector>
using namespace std;


//int prefixSum(int i, int j, vector<vector<int>> prefixMat){
//    if(i < 0 || j < 0){
//        return 0;
//    }
//    if(i >= rowSize){
//        i = rowSize - 1;
//    }
//    if(j >= colSize){
//        j = colSize -1;
//    }
//    return (prefixSum(i-1,j,prefixMat)+prefixSum(i,j-1,prefixMat)-prefixSum(i-1,j-1,prefixMat) + prefixMat[i][j]);
//}
//vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
//
//    vector<vector<int>> res(rowSize , vector<int> (colSize, 0));
//    for(int i = 0; i < rowSize; i++){
//        for(int j = 0; j < colSize; j++){
//            res[i][j] = prefixSum(i-K-1, j-K-1, mat) + prefixSum(i+K, j+K, mat) - prefixSum(i-K-1, j+K, mat) - prefixSum(i+K, j-K-1, mat);
//        }
//    }
//    return res;
//}
int extractSum(int i, int j, const vector<vector<int> >& sum);
vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K);

vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
int rowSize =  mat.size();
int colSize =  mat[0].size();
int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<vector<int>> myTest = matrixBlockSum(mat, 2);
    return 0;
}
int sizeX, sizeY;
int extractSum(int i, int j, const vector<vector<int> >& sum) {
    if (i < 0 || j < 0) return 0;
    if (i >= sizeX) i = sizeX - 1;
    if (j >= sizeY) j = sizeY - 1;
    return sum[i][j];
}
vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
    sizeX = mat.size();
    sizeY = mat[0].size();

    vector<vector<int>> sum(sizeX, vector<int>(sizeY, 0));
    // Calculate prefix matrix
    for (int i = 0; i < sizeX; i++) {
        for (int j = 0; j < sizeY; j++) {
            sum[i][j] = mat[i][j] + extractSum(i-1, j, sum) + extractSum(i, j-1, sum) - extractSum(i-1, j-1, sum);
        }
    }

    // Use prefix matrix to calculate our sum
    vector<vector<int>> ans(sizeX, vector<int>(sizeY, 0));
    for (int i = 0; i < sizeX; i++) {
        for (int j = 0; j < sizeY; j++) {
            ans[i][j] = extractSum(i+K, j+K, sum) - extractSum(i+K, j-K-1,sum) - extractSum (i-K-1, j+K, sum) + extractSum(i-K-1, j-K-1, sum);
        }
    }

    return ans;

}

