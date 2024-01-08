//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    
    Node *reverse(Node *head)
    {
        Node *nex=head,*pre=NULL,*temp=head;
        while(nex)
        {
            nex=temp->next;
            temp->next=pre;
            pre=temp;
            temp=nex;
        }
        head=pre;
    }
    struct Node * mergeResult(Node *n1,Node *n2)
    {
        // your code goes here
        
        Node *z=newNode(-1),*ans=z;
        while(n1 && n2)
        {
            while(n1 && n2 && n1->data <= n2->data)
            {
                Node *nn=newNode(n1->data);
                z->next=nn;
                z=z->next;
                n1=n1->next;
            }
            while(n2 && n1 && n2->data <n1->data)
            {
                Node *nn=newNode(n2->data);
                z->next=nn;
                z=z->next;
                n2=n2->next;
            }
        }
        while(n1)
        {
            Node *nn=newNode(n1->data);
            z->next=nn;
            z=z->next;
            n1=n1->next;
        }
        while(n2)
        {
            Node *nn=newNode(n2->data);
            z->next=nn;
            z=z->next;
            n2=n2->next;
        }
        return reverse(ans->next);
        
        
    }
       /* Node *t1,*t2,*ans=newNode(0),*tp=NULL;
        int prev=0;
        if(n1->data < n2->data)
        {
            t1=n1;
            t2=n2;
        }
        else
        {
            t1=n2;
            t2=n1;
        }
        ans->next=t1;
        prev=t1->data;
        t1=t1->next;
       // cout<<t1->data<<"\n";
        while(t1!=NULL && t2!=NULL)
        {
            if(t1->data <= t2->data)
            {
                t1=t1->next;
            }
            else
            {
                Node *z=t1->next;
                Node *nn=newNode(t2->data);
                t1->next=nn;
                nn->next=z;
                tp=t1;
                t1=t1->next;
                t2=t2->next;
            }
        } 
        while(t1!=NULL)
        {
            t1=t1->next;
        }
        while(t2!=NULL)
        {
            
            Node *nn=newNode(t2->data);
            tp->next=nn;
            //nn->next=NULL;
            tp=tp->next;
            t2=t2->next;
        }
        //Node *pallavi=reverse(ans->next);
        return ans->next;  
    }    */
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends