//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> a, int t) {
        // Your code goes here
        sort(a.begin(),a.end());
        int n=a.size();
        int ans=0,dif=INT_MAX;
        for(int i=0;i<n-2;i++)
        {
            int l=i+1,h=n-1;
            int s=a[i];
            while(l<h)
            {
                int z=s+a[l]+a[h];
               // cout<<z<<" ";
                if(z==t)
                {
                   // cout<<i<<" "<<" "<<l<<" "<<h<<endl;
                    return t;
                }
                else if(s+a[l]+a[h]>t)
                {
                    if(abs(t-z)<=dif)
                    {
                        dif=abs(t-z);
                        ans=z;
                    }
                    h--;
                }
                else
                {
                    if(abs(t-z)<dif)
                    {
                        dif=abs(t-z);
                        ans=z;
                    }
                    l++;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends