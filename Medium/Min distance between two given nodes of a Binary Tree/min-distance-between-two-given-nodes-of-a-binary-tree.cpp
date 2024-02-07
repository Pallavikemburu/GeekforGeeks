//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* fun(Node* root,int a,int b)
    {
        if(!root) return NULL;
        if(root->data==a || root->data==b) return root;
       /* if(root->left!=NULL)
        {
            m[root->left->data]=root->data;
            cout<<root->left->data<<" "<<root->data<<"\n";
        }
        if(root->right!=NULL)
        {
            m[root->right->data]=root->data;
            cout<<root->left->data<<" "<<root->data<<"\n";
        } */
        
        Node *l  =fun(root->left,a,b);
        Node *r  =fun(root->right,a,b);                       
        
        if(l!=NULL && r!=NULL) return root;
        if(l!=NULL) return l;
        if(r!=NULL) return r;
        return NULL;
    }
    void traversal(Node* root,map<int,int>&m)
    {
        if(!root) return ;
        if(root->left!=NULL) m[root->left->data]=root->data;
        if(root->right!=NULL) m[root->right->data]=root->data;
        traversal(root->left,m);
        traversal(root->right,m);
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        map<int,int>m;
        m[root->data]=0;
        traversal(root,m);
        Node *z=fun(root,a,b);
        int c=0,p=z->data;
       /* for(auto i:m)
        {
            cout<<i.first<<" "<<i.second<<"\n";
        } */
        while(a!=p)
        {
            c++;
            a=m[a];
        }
        while(b!=p)
        {
            c++;
            b=m[b];
        } 
        return c;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends