class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        priority_queue<pair<int, int>> pq;
        vector<int> res;
        int i = 0 , j = 0;
        
        while (j < n){
            pq.push({arr[j], j});
            if (j-i+1 == k){
                while (pq.size() and (pq.top().second < i  or pq.top().second > j))
                    pq.pop();
                res.push_back(pq.top().first);
                ++i;
            }
            ++j;
        }
        return res;
    }
};