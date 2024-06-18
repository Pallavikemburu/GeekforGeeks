//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int rectanglesInCircle(int r) {
        // code here
        int ar=2*r;
        //cout<<ar<<"\n";
        int c=0;
        for(int i=1;i<2*r;i++)
        {
            for(int j=1;j<2*r;j++)
            {
                if(((i*i)+(j*j))<=ar*ar)
                {
                   // if(i>r && j>r) continue;
                    //cout<<i<<" "<<j<<"\n";
                    c++;
                }
                
            }
        }
        return c;
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
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
// } Driver Code Ends