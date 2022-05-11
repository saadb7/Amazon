class Solution
{
    public:
    Node* temp = NULL;
    void  shorten (int M , int N , Node* &d_tail){

        while (M--){ 
            d_tail -> next = temp;
            d_tail = d_tail -> next;
            temp = temp -> next;
            if (!temp) return;
        }
        
        while (N--){
            temp = temp -> next;
            if (!temp)
                return ;
        }
        
    }
    void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here
        Node* dummy = new Node(0);
        Node* d_tail = dummy;
        temp = head;
        
        while (temp)
            shorten (M , N , d_tail);
        d_tail -> next = NULL;
        head = dummy;
        
        
    }
};