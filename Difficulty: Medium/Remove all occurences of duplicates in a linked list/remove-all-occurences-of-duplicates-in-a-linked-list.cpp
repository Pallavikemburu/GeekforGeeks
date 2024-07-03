//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++
/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* z) {
        // code here
        Node *ans=new Node(-1);
       // ans->next=z;
        Node *head=z;
        Node *p=ans;
        while(head)
        {
           // cout<<head->data<<" ";
            //if(head->next==NULL) break;
            int f=0;
            while(head->next!=NULL && head->data==head->next->data)
            {
                f=1;
                head=head->next;
            }
            if(f==0)
            {
                ans->next=new Node(head->data);
                ans=ans->next;
            }
            head=head->next;
            
           // prev=head->data;
        }
        return p->next;
    }
};

//{ Driver Code Starts.
/* Function to print linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;

        cin >> N;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < N; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        head = ob.removeAllDuplicates(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends