//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:

    //Function to return a tree created from postorder and inoreder traversals.
    int findind(int in[], int e,int n)
    {
        for(int i=0;i<n;i++)
        {
            if(in[i]==e) 
            {
                return i;
            }
        }
        return -1;
    }
    ////  l-- inorder start      r -- inorder end
    ////  p -- postorder start   q -- postorder end
    
    Node* fun(int in[], int post[],int l,int h,int p,int q,int n)
    {
        if(l>h || p>q)
        {
            return NULL;
        }
        int pos=findind(in,post[q],n);
        Node *t=new Node(in[pos]);
       // cout<<t->data<<" ";
      //  cout<<t->data<<" ";
        int d=pos-l;
        t->left=fun(in,post,l,pos-1,p,p+d-1,n);
        t->right=fun(in,post,pos+1,h,p+d,q-1,n);
        return t;
    }
   
    Node *buildTree(int in[], int post[], int n) {
        // Your code here
       // int p=findind(in,post[n],n);
       // Node *ans=new Node(post[n-1]);
       // ans->right=fun(in,post,p+1,n-1,n-2,n);
       // ans->left=fun(in,post,0,p-1,n-2,n);
        Node *ans=fun(in,post,0,n-1,0,n-1,n);
       // return NULL;
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends