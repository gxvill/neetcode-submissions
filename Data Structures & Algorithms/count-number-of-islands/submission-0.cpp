class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1'){
                    num++;
                    dfs(grid, i, j);
                }
            }
        }
        return num;
    }
    void dfs(vector<vector<char>>& grid, int row, int col){
        // bounds check
        int ROWS = grid.size();
        int COLS = grid[0].size();
        if((row < 0 || row >= ROWS) || (col < 0 || col >= COLS)){
            return;
        }
        if(grid[row][col] == '0'){
            return;
        }

        grid[row][col] = '0';

        dfs(grid, row - 1, col);  // up
        dfs(grid, row, col + 1);  // right  
        dfs(grid, row + 1, col);  // down
        dfs(grid, row, col - 1);  // left

        // change 1 to 0
        return;

    }
};
