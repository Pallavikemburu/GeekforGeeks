//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // a: given vector
    // return the p vector P that hold p except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& a) {

        // code here
        long long int p=1;
        int z=0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=0)
            {
                p=p*a[i];
            }
            else
            {
                 z++;
            }
        }
        vector<long long int>ans;
        if(z==1)
        {
            for(int i=0;i<a.size();i++)
            {
                if(a[i]==0)
                {
                    ans.push_back(p);
                }
                else ans.push_back(0);
            }
        }
        else if(z>1)
        {
            for(int i=0;i<a.size();i++)
            {
                ans.push_back(0);
            }
        }
        else
        {
            for(int i=0;i<a.size();i++)
            {
                ans.push_back(p/a[i]);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends