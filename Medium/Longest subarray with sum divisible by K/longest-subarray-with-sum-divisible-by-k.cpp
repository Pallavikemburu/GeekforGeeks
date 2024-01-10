//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int a[], int n, int k)
	{
	    // Complete the function
	    map<int,int>m;
	    m[0]=-1;
	    int ans=0,s=0;
	    for(int i=0;i<n;i++)
	    {
	        s=((s%k)+(a[i]%k+k))%k;
	        if(m.find(s)==m.end())
	        {
	            m[s]=i;
	        }
	        else
	        {
	            ans=max(ans,i-m[s]);
	        }
	    }
	    return ans;
	}
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends