//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int k,vector<int>& arr1, vector<int>& arr2)
    {
        int n=arr1.size(),m=arr2.size();
        vector<int>a;
        int i;
        for(i=0;i<n;i++)
        {
            a.push_back(arr1[i]);
        }
        for(i=0;i<m;i++)
        {
            a.push_back(arr2[i]);
        }
        sort(a.begin(),a.end());
        /*for(i=0;i<m+n-1;i++)
        {
            cout<<a[i]<<" ";
        }*/
        return a[k-1];
    }
};


//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends