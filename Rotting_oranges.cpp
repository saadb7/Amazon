class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        
        int di[4] = {1,0,-1,0} , dj[4] = {0,1,0,-1} , res = 0 , m = size(grid) , 
        n = size(grid[0]) , oc = 0;
        
        queue<pair <int , int >> q;
        for (int i = 0 ; i < m ; ++i){
            for (int j = 0 ; j < n ; ++j)
                if (grid[i][j] == 2)
                    q.push({i , j});
                else if (grid[i][j] == 1)
                    ++oc;
            
        }
        if (q.empty()){
            if (oc)
                return -1;
            return 0;
        }
        
        while (q.size()){
            
            int sz = q.size();
            while (sz--){
                
                auto [i,j] = q.front();
                q.pop();
                
                for (int dir = 0 ; dir < 4 ; ++dir){
                    int ni = i + di[dir] , nj = j + dj[dir];
                    if (ni >= 0 and ni < m and nj >= 0 and nj < n 
                       and grid[ni][nj] == 1)
                        q.push({ni, nj}) , grid[ni][nj] = 2 , --oc;
                }
            }
            ++res;
            
        }
        if (oc)
            return -1;
        return res-1;
    }
};