class Solution {
  public:
    Node* ult;
    unordered_map <Node* , Node*> PL;
    int t;
    void dfs (Node* root , Node* parent){
        if (!root)
            return ;
        
        dfs (root-> left , root);
        if (root -> data == t)
            ult = root;
        PL[root] = parent;
        dfs (root -> right , root);
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        t = target;
        int res = 0;
        // ult = root;
        dfs(root , NULL);
        unordered_map <Node* , bool> visited;
        queue<pair <Node* , int>> q;
        q.push({ult , 0});
        visited[ult] = true;
        // cout << ult -> data << endl;
        while (q.size()){
            
            Node* node = q.front().first;
            
            int dis = q.front().second;
            // cout << node -> data << " " << dis << endl;
            res = max (dis , res);
            q.pop();
            if (node -> left and !visited[node -> left])
                q.push({node -> left , dis + 1}) , visited[node -> left] = true;
            
            if (node -> right and !visited[node -> right])
                q.push({node -> right , dis +1}) , visited[node -> right] = true;
                
            if (PL[node] and !visited[PL[node]])
                q.push({PL[node] , dis + 1 }) , visited[PL[node]] = true;
            
        }
        // cout 
        return res;
        
    }
};