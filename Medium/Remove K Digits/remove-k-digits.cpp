//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string a, int k) {
        if(a.size()==k) return "0";
        stack<char>s;
        int i=0;
        string ans="";
        while(i<a.size())
        {
            while(!s.empty() and a[i]>=s.top() and k)
            {
                s.push(a[i]);
                i++;
            }
            if(s.empty())
            {
               /* while(a[i]=='0')
                {
                    i++;
                }  */ 
                s.push(a[i]);
                i++;
            }
            while(!s.empty() and a[i]<s.top() and k)
            {
                s.pop();
                k--;
            }
            if(s.empty())
            {
               /* while(a[i]=='0')
                {
                    i++;
                }   */
                s.push(a[i]);
                i++;
            }
            if(k==0)
            {
                while(i<a.size())
                {
                    s.push(a[i]);
                    i++;
                }
            }
        }
        while(k)
        {
            s.pop();
            k--;
        }
        while(!s.empty())
        {
            ans+=s.top();
            s.pop();
        }
       // cout<<ans<<" ";
        string res="";
        for(int i=ans.size()-1;i>=0;i--)
        {
            if(ans[i]=='0' and res.size()==0)
            {
    
            }
            else
            {
                res+=ans[i];
            }
        }
        if(res.size()==0) return "0";
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends