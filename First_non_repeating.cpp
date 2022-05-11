class Solution{
public:
    vector<string> solve (int n , set<string> &con , string curr){
        
        vector<string> res;
        
        // cout << curr << endl;
        for (string s : con){
            string temp = s.substr(0,n);
            if (temp == curr)
            res.push_back(s);
        }
        return res;
        
    }
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        set <string> con(contact , contact+n);
        vector<vector<string>> ans(s.size());
        for (int i = 1 ; i <= s.size() ; ++i){
            
            string curr = s.substr(0,i);
            vector<string> v = solve (i , con , curr);
            if (!v.size())
                v = {"0"};
            ans[i-1] = v;
            
            
        }
        return ans;
    }
};