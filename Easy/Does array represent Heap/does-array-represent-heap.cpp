//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool isMaxHeap(int a[], int n)
    {
        // Your code goes here
        int i=0;
        while((2*i)+1<n)
        {
            int p=(2*i)+1;
            int q=-1;
            if(((2*i)+2)<n)
                 q=(2*i)+2;
            if(a[i]<a[p] || a[i]<a[q]) return false;
            i++;
            //cout<<p<<" "<<q<<"\n";
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends