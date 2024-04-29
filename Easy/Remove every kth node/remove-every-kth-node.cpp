//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};


void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    
    *tail_ref = new_node;
}


// } Driver Code Ends
/* Link list Node 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

/*You are required to complete this method*/

/* Function to get the middle of the linked list*/
/*K will always be in range */

class Solution {
    public:
    Node* deleteK(Node *head,int k){
      //Your code here
          if(k==1 || head==NULL) return NULL;
          Node* prev=NULL;
          Node* temp=head;
          while(temp)
          {
                int z=0;
                while(temp!=NULL && z<k-1)
                {
                   prev=temp;
                   temp=temp->next;
                   z++;
                }
                if(temp==NULL)
                {
                    break;
                }
                prev->next=temp->next;
                temp->next=NULL;
                temp=prev->next;
          }
        return head;
    //  k=k-1;
    //  Node* ans=head;
    //   while(true) 
    //   {
    //       int t=k-1;
    //       while(head  && t>0)
    //       {
    //           t--;
    //           head=head->next;
    //       }
    //       if(head && head->next && head->next->next)
    //       {
    //           Node *temp=head->next->next;
    //           head->next=temp;
    //           head=head->next;
    //       }
    //       else break;
    //   }
    //  return ans;
    
    }
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main()
{
  int T,i,n,l;
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
        int K;
        cin>>K;
        Solution obj;
        Node *res = obj.deleteK(head,K);
        Node *temp = res;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends