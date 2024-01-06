//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int s[(2*100000)+1]={0};
    void sieve(int n)
    {
        int m=n;
        s[0]=0;
        s[1]=0;
        for(int i=2;i<=m;i++)
        {
            s[i]=i;
        }
        for(int i=2;i<=m;i=i+2)
        {
            s[i]=2;
        }
        for(int i=3;(i*i)<=m;i++)
        {
            if(s[i]==i)
            {
                for(int j=i*i;j<=m;j=j+i)
                {
                    if(s[j]==j)
                    {
                        s[j]=i;
                    }
                }
            }
        }
    }
    int fun(int n)
    {
        int c=0;
        while(n>1)
        {
            c++;
            n=n/s[n];
        }
        return c;
    }
	int sumOfPowers(int a, int b){
	    // Code here
	    sieve(b);
	    int ans=0;
	    for(int i=a;i<=b;i++)
	    {
	        int z=fun(i);
	        //cout<<z<<" ";
	        ans=ans+z;
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends