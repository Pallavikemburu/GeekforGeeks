//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* fun(struct Node *head)
    {
        // code here
        // return head of reversed list
        Node *nex=head,*pre=NULL,*temp=head;
        while(nex)
        {
            nex=temp->next;
            temp->next=pre;
            pre=temp;
            temp=nex;
        }
        head=pre;
        return head;
    }
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        // code here
        Node *a=fun(num1);
        Node *b=fun(num2);
        Node *t=new Node(-1);
        Node *ans=t;
        Node *p=a,*q=b;
        int c=0;
        while(p && q)
        {
            int x=p->data;
            int y=q->data;
            //cout<<x<<" "<<y<<endl;
            int k=x+y;
            int z=(k+c)%10;
            c=(k+c)/10;
            Node *n=new Node(z);
          //  cout<<n->data<<" ";
            t->next=n;
            t=t->next;
            p=p->next;
            q=q->next;
           // cout<<k<<" "<<c<<"\n";
        }
       // cout<<c<<" "<<"\n";
        while(p)
        {
            int x=p->data;
            int z=(x+c)%10;
            c=(x+c)/10;
            Node *n=new Node(z);
            t->next=n;
            t=t->next;
            p=p->next;
        }
        while(q)
        {
            int y=q->data;
            int z=(y+c)%10;
            c=(y+c)/10;
            Node *n=new Node(z);
            t->next=n;
            t=t->next;
            q=q->next;
        }
        if(c)
        {
            Node *n=new Node(c);
            t->next=n;
            t=t->next;
        }
        Node *pk=fun(ans->next);
        while(pk!=NULL && pk->data==0)
        {
            pk=pk->next;
        }
        if(pk==NULL) return new Node(0);
        return pk;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends