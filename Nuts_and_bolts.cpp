class Solution{
public:	

    static bool cmp ( char &a ,  char &b){ 
        // return m[a] < m[b];
        // cout << m[a] << endl;
        return a < b;
    }
	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    
	    sort(nuts, nuts+n , cmp);
	    sort(bolts , bolts+n , cmp);
	    
	}

};