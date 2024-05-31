//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    int swapNibbles(int n){
        // code here
        int temp=n,i,s=0;
        int b[8];
        for(int i=7;i>=0;i--)
        {
            b[7-i]=((n>>i)&1);
        }
        for(int i=0;i<=7;i++)
        {
            //cout<<b[i]<<" ";
        }
        int k=3;
        for(i=0;i<=k;i++)
        {
            b[i]=b[i]^b[i+k+1];
         //   cout<<b[i]<<" " << b[i+k-1]<<" ";
        }
        
            
        for(i=k+1;i<=7;i++)
        {
            b[i]=b[i]^b[i-k-1];
        }
        for(i=0;i<=k;i++)
        {
            b[i]=b[i]^b[k+i+1];
        }
        for(int i=0;i<=7;i++)
        {
            if(b[i]==1)
            s=s+pow(2,7-i);
        }
       
        return s;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
// } Driver Code Ends