//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    void fun(string s,int o,int z,int n,vector<string>&ans)
    {
        if(s.size()>n || z>o) return;
        if(s.size()==n)
        {
           // cout<<z<<" "<<o<<"\n";
            ans.push_back(s);
            return;
        }
        fun(s+'1',o+1,z,n,ans);
        fun(s+'0',o,z+1,n,ans);
    }
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    vector<string>ans;
	    //int z=n/2;
	    string s="";
	    int o=0,z=0;
	    fun(s,o,z,n,ans);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends