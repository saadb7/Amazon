class Solution {
  public:
    
    int t[501][201][2];
    int sell (int a[], int k , int n ,bool can = true , int i = 0){
        
        if (i == n){
            if (k >= 0)
                return 0;
            else return -100000;
        }
        if (t[i][k][can] != -1)
            return t[i][k][can];
        int skip = sell (a, k , n , can , i+1);
        int make;
        if (can){
            make = -a[i] + sell (a , k , n , !can , i+1);
        }
        else make = a[i] + sell (a, k-1 , n , !can , i+1);
        
        return t[i][k][can] = max (skip , make);
    }
    int maxProfit(int K, int N, int A[]) {
        // code here
        memset(t , -1 , sizeof (t));
        return sell(A , K , N );
    }
};