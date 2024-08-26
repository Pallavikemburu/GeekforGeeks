//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method*/
    int wildCard(string a, string s) {
        // code here
        int n = a.size(), m = s.size(); int dp[n+2][m+2];
        memset(dp, 0, sizeof(dp)); dp[n][m] = 1;
        for ( int i = n; i>=0; i-- )
        {
            for ( int j = m; j>=0; j-- )
            {
                if ( a[i] == s[j] || a[i] == '?' ) 
                {
                    dp[i][j] |= dp[i+1][j+1];
                }
                if ( a[i] == '*' )
                {
                    dp[i][j] |= dp[i+1][j+1];
                    dp[i][j] |= dp[i][j+1];
                    dp[i][j] |= dp[i+1][j];
                } 
            }
        } 
        return dp[0][0];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends