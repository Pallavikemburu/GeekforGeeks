//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int fun2(int a[],int l,int m,int r)
    {
        int x=(m-l+1),y=(r-m);
        vector<int> p(x),q(y);
        int i=0,j=0,k,ans=0;
        while(i<x)
        {
            p[i]=a[l+i];
            i++;
        }
        while(j<y)
        {
            q[j]=a[m+1+j];
            j++;
        }
        i=0,j=0,k=0;
        while(i<x && j<y)
        {
            if(p[i]<=q[j])
            {
                a[l+k]=p[i++];
                k++;
            }
            else
            {
                a[l+k]=q[j++];
                ans=ans+(x-i);
                k++;
            }
        }
        while(i<x)
        {
            a[l+k]=p[i];
            i++;
            k++;
        }
        while(j<y)
        {
            a[l+k]=q[j];
            j++;
            k++;
        }
        return ans;
    }
    int fun(int a[],int l,int r)
    {
        int ans=0;
        if(l<r)
        {
            int m=l+(r-l)/2;
            ans=ans+fun(a,l,m);
            ans=ans+fun(a,m+1,r);
            ans=ans+fun2(a,l,m,r);
        }
        return ans;
    }
    int countPairs(int a[] , int n ) 
    {
        // Your code goes here   
        for(int i=0;i<n;i++)
        {
            a[i]=(i*a[i]);
        }
        return fun(a,0,n-1);
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends