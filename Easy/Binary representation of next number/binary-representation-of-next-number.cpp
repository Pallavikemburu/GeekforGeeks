//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        bool z = true;
        for(int i=s.length()-1;i>=0;i--) 
        {
            if(s[i]=='0') 
            {
                z = false;
                s[i]='1';
                break;
            }
            else 
            {
                s[i]='0';
            }
        }
        if(z) 
        {
            s = '1'+s;
        }
        else 
        {
            while(s[0]=='0') 
            {
                s.erase(s.begin());
            }
        }
        return s;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends