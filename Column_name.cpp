class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string col = "";
        while (n--){
            col += char ('A' + n%26);
            n /= 26;
        }
        reverse (col.begin() , col.end());
        return col;
    }
};