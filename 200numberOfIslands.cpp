class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int k = 0; k < grid[0].size();k++){
                if(grid[i][k] == '1' && calculateOneArea(grid, i, k) >= 1){
                    count++;
                }
            }
        }
        return count;
    }

    int calculateOneArea(vector<vector<char>>& grid, int i, int k){
        if(i< 0 || i >= grid.size() || k < 0 || k >= grid[0].size()){
            return 0;
        }
        if(grid[i][k] == '1'){
            //flag it as visited
            grid[i][k] = '0';
            return (calculateOneArea(grid, i-1, k) + calculateOneArea(grid, i+1, k) + calculateOneArea(grid, i, k-1) + calculateOneArea(grid, i, k+1) + 1);
        }
        return 0;
    }
};