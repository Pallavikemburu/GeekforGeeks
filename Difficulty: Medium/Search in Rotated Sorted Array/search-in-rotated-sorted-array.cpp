//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& a, int k) {
        // complete the function here

        int l=0,h=a.size()-1;
        while(l<=h)
        {
            int m=(l+h)/2;
            if(a[m]==k)
            {
                return m;
            }
            if(a[l]<=a[m])
            {
                if(a[l]<=k && a[m]>k) 
                {
                    h=m-1;
                }
                else l=m+1;
            }
            else
            {
                if(a[m]<k && a[h]>=k)
                {
                    l=m+1;
                }
                else
                {
                    h=m-1;
                }
            }
            // else if(a[m]<k and a[l]<a[m])
            // {
            //     l=m+1;
            // }
            // else if(a[m]<k and a[l]>a[m])
            // {
                
            // }
            // else if([l]<k and a[h]>k)
            // {
                
            // }
            // else if([l]<k and a[h]>k)
            // {
                
            // }
        }
        return -1;
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
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends