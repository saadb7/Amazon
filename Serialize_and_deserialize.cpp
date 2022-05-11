class Solution
{
    public:
    vector<int> dfs;
    int i = 0 ;
    void serial (Node* root){
        if (!root){
            dfs.push_back(-1);
            return;
        }
        dfs.push_back(root -> data);
        serial (root -> left);
        serial (root -> right);
    }
    Node* deserial (vector<int> &a){
        
        if (a[i] == -1){
            ++i;
            return NULL;
        }
        Node* root = new Node(a[i++]);
        root -> left = deserial(a);
        root -> right = deserial(a);
        
        return root;
    }
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        //Your code here
        serial (root);
        // for (int &x : dfs)
        //     cout << x << " ";
        return dfs;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
        
        return deserial(A);
    //   return NULL;
    }

};