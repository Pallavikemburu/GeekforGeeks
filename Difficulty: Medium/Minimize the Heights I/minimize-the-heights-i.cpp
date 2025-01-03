//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int getMinDiff(int k, vector<int> &a) {
        // code here
        int n=a.size();
        sort(a.begin() , a.end()) ; 
        int ans = a[n-1] - a[0] ; 
        for(int i=1;i<n;i++)
        {
            int mini = min(a[0]+k , a[i]-k) ; 
            int maxi = max(a[i-1]+k , a[n-1]-k) ; 
            ans = min(ans , maxi - mini) ; 
        }
        return ans; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();

    while (t--) {
        int k;
        cin >> k;
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.getMinDiff(k, arr);
        cout << res;

        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends