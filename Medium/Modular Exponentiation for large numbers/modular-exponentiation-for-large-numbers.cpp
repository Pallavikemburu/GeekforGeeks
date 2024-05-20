//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    long long int power(long long int a,long long int b,long long int m)
        {
	        long long int res=1;
	        while(b)
	        {
		        if(b&1)
		        {
			        b=b-1;
			        res=(res%m * a%m)%m;
		        }
	        	else
		        {
			        b=b/2;
		        	a=(a%m * a%m)%m;
		        }
	        }
	        return res;
        }
		long long int PowMod(long long int x,long long int n,long long int m)
		{
		    // Code here
		    return power(x,n,m);
		    
		}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends