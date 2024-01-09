//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int n){
        // code here
        vector<int>v;
	    v.push_back(1);
	    for(long long i=1;i<=n;i++)
	    {
		    int c=0;
		    for(long long j=0;j<v.size();j++)
		    {
			    long long f=(1LL*v[j]*i*1LL)+c;
			    int l=f%10;
			    v[j]=l;
			    c=(f/10);
		    }
		    while(c)
		    {
		        int p=c%10;
		        v.push_back(p);
		        c=c/10;
		    }
	    }
	    reverse(v.begin(),v.end());
	    return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends