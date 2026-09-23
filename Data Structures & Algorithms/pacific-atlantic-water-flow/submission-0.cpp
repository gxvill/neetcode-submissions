class Solution {
    // created to make the change of directions easier
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();

        // hash set equivalents
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));

        // dfs on top and bottom
        for(int c = 0; c < COLS; ++c){
            dfs(0, c, pac, heights);
            dfs(ROWS - 1, c, atl, heights);
        }

        // dfs on left and right
        for(int r = 0; r < ROWS; ++r){
            dfs(r, 0, pac, heights);
            dfs(r, COLS - 1, atl, heights);
        }

        vector<vector<int>> res;

        // iterate through hash sets to see where a position is true for both
        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                if(pac[r][c] && atl[r][c]){
                    res.push_back({r,c});
                }
            }
        }

        return res;
    }
    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>> heights){
        ocean[r][c] = true;
        // iterate through different direction
        for(auto [dr, dc] : dir){
            int nr = r + dr;
            int nc = c + dc;

            if (nr >= 0 && nr < heights.size() &&
                nc >= 0 && nc < heights[0].size() &&
                !ocean[nr][nc] && heights[nr][nc]>= heights[r][c]) {
                dfs(nr, nc, ocean, heights);
            }
        }
        
    }
};



