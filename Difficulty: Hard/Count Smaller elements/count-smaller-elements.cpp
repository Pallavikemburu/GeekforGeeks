//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++

class Solution {
  public:
    // void merge(vector<int> &a,vector<int> &ans,int l,int m,int h)
    // {
    //     vector<int>temp(h-l+1,0);
    //     int i=l,j=m+1,k=0;
    //     while(i<=m && j<=h)
    //     {
    //         if(a[i]<=a[j])
    //         {
    //             temp[k]=a[i];
    //             i++;
    //             k++;
    //         }
    //         else
    //         {
    //             temp[k]=a[j];
    //             j++;
    //             k++;
                
    //         }
    //     }
    //     while(i<=m)
    //     {
    //         temp[k]=a[i];
    //         i++;
    //         k++;
    //     }
    //     while(j<=h)
    //     {
    //         temp[k]=a[j];
    //         j++;
    //         k++;
    //     }
    //     for(int i=0;i<(h-l+1);i++)
    //     {
    //         a[i+l]=temp[i];
    //       // cout<<temp[i]<<" ";
    //     }
    //   // cout<<"\n";
    // }
    // void mergesort(vector<int> &a,vector<int> &ans,int l,int h)
    // {
    //     if(l<h)
    //     {
    //         int m=(l+h)/2;
    //         mergesort(a,ans,l,m);
    //         mergesort(a,ans,m+1,h);
    //         merge(a,ans,l,m,h);
    //     }
    // }
    // vector<int> constructLowerArray(vector<int> &a) {
    //     // code here
    //     vector<int>ans(a.size());
    //     mergesort(a,ans,0,a.size()-1);
    //   // for(auto i:a) cout<<i<<" ";
    //     return ans;
    // }
    vector<int> constructLowerArray(vector<int> &arr) {
        int n = arr.size();
        vector<int> z(arr.begin(), arr.end());
        sort(z.begin(), z.end());
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) 
        {
            auto idx = lower_bound(z.begin(), z.end(), arr[i]);
            z.erase(idx);
            ans[i] = idx - z.begin();
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
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends