//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {

        // your code here
        int n=arr.size();
        int globalMin=arr[0], globalMax=arr[0], currMin=0, currMax=0, totalSum=0;
        for(int i=0; i<n; i++){
            totalSum +=arr[i];
            currMax = max(currMax+arr[i], arr[i]);
            currMin = min(currMin+arr[i], arr[i]);
            globalMax = max(currMax, globalMax);
            globalMin = min(currMin, globalMin);
        }
        return max(totalSum-globalMin,globalMax);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends