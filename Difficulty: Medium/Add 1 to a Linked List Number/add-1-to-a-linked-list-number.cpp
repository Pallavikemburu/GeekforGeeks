//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
//User function template for C++

/* 

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

class Solution
{
    public:
    Node* rev(Node *head)
    {
        Node *a=head,*b=NULL,*c=NULL;
        {
            while(a)
            {
                c=a->next;
                a->next=b;
                b=a;
                a=c;
            }
        }
       /* Node *t=b;
        while(t)
        {
            cout<<t->data<<" ";
            t=t->next;
        }*/
        return b;
        
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node *t=rev(head);
        Node *z=t;
        int c=1;
        while(z)
        {
            z->data=z->data+c;
            if(z->data>9)
            {
                c=1;
            }
            else
            {
                c=0;
            }
            z=z->next;
        }
        Node *p=new Node(1);
        Node *k=rev(t);
        if(c)
        {
            p->next=k;
        }
        else
        {
            return k;
        }
        return p;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends