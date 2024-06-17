//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     float fun(int a[],int b[],int c[])
     {
        float z=((float)b[1]-a[1]) / ((float)b[0]-a[0]);
        return (float)c[1]-a[1]-z*(c[0]-a[0]);
    }
    string doIntersect(int a[], int b[], int c[], int d[]) {
        // code here
        float p=fun(a,b,c);
        float q=fun(a,b,d);
        float r=fun(c,d,a);
        float s=fun(c,d,b);
        
        if(p*q<=0 && r*s<=0)
        {
            return "true";
        }
        return "false";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p1[2], q1[2], p2[2], q2[2];
        cin >> p1[0] >> p1[1] >> q1[0] >> q1[1] >> p2[0] >> p2[1] >> q2[0] >> q2[1];
        // if (q2[1] == -2) {
        //     cout << "true" << endl;
        //     return 0;
        // }
        Solution ob;
        // int a = ob.doIntersect(p1, q1, p2, q2);
        // if (a)
        cout << ob.doIntersect(p1, q1, p2, q2) << "\n";
    }
}
// } Driver Code Ends