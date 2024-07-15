//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        string ans="";
        d=d-1;
        s=s-1;
        while(d>0 && s>0)
        {
            
            while(d and s>=9)
            {
                ans='9'+ans;
                s=s-9;
                d--;
            }
            while(d and s>=8)
            {
                ans='8'+ans;
                s=s-8;
                d--;
            }
            while(d and s>=7)
            {
                ans='7'+ans;
                s=s-7;
                d--;
            }
            while(d and s>=6)
            {
                ans='6'+ans;
                s=s-6;
                d--;
            }
            while(d and s>=5)
            {
                ans='5'+ans;
                s=s-5;
                d--;
            }
            while(d and s>=4)
            {
                ans='4'+ans;
                s=s-4;
                d--;
            }
            while(d and s>=3)
            {
                ans='3'+ans;
                s=s-3;
                d--;
            }
            while(d and s>=2)
            {
                ans='2'+ans;
                s=s-2;
                d--;
            }
            while(d and s>=1)
            {
                ans='1'+ans;
                s=s-1;
                d--;
            }
        }
        while(d)
        {
            d--;
            ans='0'+ans;
        }
        if(s<9)
        {
            ans=to_string(s+1)+ans;
        }
        else if(s==0)
        {
            ans='1'+ans;
        }
        else
        {
            return "-1";
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends