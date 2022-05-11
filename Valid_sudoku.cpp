class Solution{
public:
    int isValid(vector<vector<int>> board){
        // code here
        for (int i = 0 ; i < 9 ; ++i){
           for (int j = 0 ; j < 9 ; ++j){
               if (board[i][j] != 0){
                //   cout << board[i][j] << " ";
                   bool temp = valid (board , i , j , board[i][j]);
                   if (!temp)
                       return false;
               }
           }
        //   cout << endl;
       } 
        return true;
    }
    bool valid (vector<vector<int>> &board , int row , int col , int c){
        
        int startR = (row/3) *3 , startC = (col/3) *3 ;
        for (int i = 0 ; i < 9 ; ++i){
            
            if (i != col and board[row][i] == c)
                return false;
            if (i != row and board[i][col] == c)
                return false;
            if (( (startR + i/3) != row and (startC + i%3) != col) and board[startR + i/3]
               [startC + i%3] == c)
                return false;
        }
        return true;
    }
};