//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countNumberswith4(int n) {
        // code here
        vector<string>s;
        for(int i = 1 ; i <= n ; i++)
        {
            s.push_back(to_string(i));
        }
        int c = 0;
        for(int i = 0 ; i < s.size() ; i++)
        {
            for(int j = 0; j < s[i].size() ; j++)
            {
                if(s[i][j] == '4')
                {
                    c++;
                    break;
                }
            }
        }
        return c;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends