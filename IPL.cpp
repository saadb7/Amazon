class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans = 0;
        
        for (int i = 1 ; i < size(arr) - 1 ; ++i){
            if (arr[i-1] < arr[i] and arr[i+1] < arr[i]){
                int L = i-1 , R = i+1;
                while (L >= 0 and arr[L] < arr[L+1])
                    L--;
                while ( R < size(arr) and arr[R] < arr[R-1])
                    R++;
                
                ans = max (ans , R - L - 1);
                
            }
        }
        return ans;
    }
};