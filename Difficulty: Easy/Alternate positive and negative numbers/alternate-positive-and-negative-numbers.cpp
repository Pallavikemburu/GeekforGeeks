//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    vector<int>res(vector<int> &arr){
        vector<int>pos;
        vector<int>neg;
        for (int i:arr){
            if (i>=0){
                pos.push_back(i);
            }
            else{
                neg .push_back(i);
            }
        }
        int n=arr.size();
        int m=pos.size();
        int p=neg.size();
        vector<int>result;
        int posi=0;
        int negi=0;
        
        for(int i=0;i<n;i++){
             if (posi<m){
                   result.push_back(pos[posi]);
                   posi++;
             }
             if (negi<p){
                  result.push_back(neg[negi]);
                  negi++;
             }

        }
        return result;
     }
    void rearrange(vector<int> &arr) {
        
       
       arr= res(arr);   // code here
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends