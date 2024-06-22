//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string s) {

        // code here
        long long int maxi=-1;
        for(int i=0;i<s.length();i++)
        {
            long long int n=0;
            bool f=true;
            while(s[i]!=' ' && (s[i]>='0' && s[i]<='9') && i<s.length())
            {
                int x=(s[i]-'0');
                if(x==9)
                {
                    f=false;
                }
                n=(n*10)+x;
                i++;
            }
            if(f==true)
            {
                maxi=max(maxi,n);
            }
        }
        if(maxi==0)
        {
            return -1;
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends