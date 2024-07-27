//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string str){
    //complete the function here
        vector<int>dp(str.size(), 0);
        int n = str.size();
        for(int i = n-2; i >= 0; i--){
            vector<int>tmp = dp;
            for(int j = i+1; j < n; j ++){
                if(str[i] == str[j]){
                    tmp[j] = dp[j-1];
                } else {
                    tmp[j] =  min(1 + dp[j], 1 + tmp[j-1]);
                }
            }
            dp = tmp;
        }
        return dp[str.size()-1];
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends