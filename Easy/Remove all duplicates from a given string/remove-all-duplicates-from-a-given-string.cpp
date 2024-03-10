//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	 string ans="";

     unordered_map<char,int>mp;

     for(int i: str)

        mp[i]++;

     for(int i=str.size();i>=0;i--)

     {

         if(mp[str[i]]>1)

         {

             mp[str[i]]--;

         }

         else

         ans+=str[i];

     }

     reverse(ans.begin(),ans.end());

     return ans;

 }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends