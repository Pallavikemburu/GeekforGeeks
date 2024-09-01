//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        // Code here
        int i = a.size()-1, j = b.size()-1;
        int ans = 0, p = 0, q = 0;
        while(i >= 0 && j >= 0)
        {
            if(a[i] > b[j])     p += a[i--];
            else if(a[i] < b[j])    q += b[j--];
            else
            {
                ans += max(p + a[i--], q + b[j--]);
                p = q = 0;
            }
        }
        while(i >= 0)   p += a[i--];
        while(j >= 0)   q += b[j--];
        ans += max(p, q);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        long long ans = ob.maxPathSum(arr1, arr2);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends