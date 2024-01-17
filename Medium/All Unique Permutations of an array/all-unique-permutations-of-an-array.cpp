//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
        // code here
    
     void A(int n,vector<int> &a,vector<int> &ds,vector<vector<int>>&z,int f[])
	    {
	        if(ds.size()==n)
	        {
	            z.push_back(ds);
	        }
	        for(int i=0;i<n;i++)
	        {
	            if(f[i]==0)
	            {
	                f[i]=1;
	                ds.push_back(a[i]);
	                A(n,a,ds,z,f);
	                f[i]=0;
	                ds.pop_back();
	            }
	        }
	    }
	    vector<vector<int>> uniquePerms(vector<int> a ,int n) 
		
		{
		    // Code here there
		    vector<int> ds;
		    vector<vector<int>>z;
		   // int n=a.size();
		    int f[9]={0};
		    A(n,a,ds,z,f);
		    sort(z.begin(),z.end());
		    z.erase(unique(z.begin(),z.end()),z.end());
		    return z;
		} 
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends