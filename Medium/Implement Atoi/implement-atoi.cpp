//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int neg=0,i=0,ans=0;
        if(s[0]=='-')
        {
            i=1;
            neg=1;
        }
        while(i<s.size())
        {
            int z=s[i]-'0';
            if(z>=0 && z<=9 )
            {
                ans=ans*10+z;
            }
            else return -1;
            i++;
        }
        if(neg==1)
        {
            ans=ans*-1;
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
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends