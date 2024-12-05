//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    void sort012(vector<int>&a)
    {
        // code here 
        int n=a.size();
        int start=0,num=0,end=n-1;
        while(num<=end)
        {
            if(a[num]==0)
            {
                swap(a[num],a[start]);
                num++;
                start++;
            }
            else if(a[num]==2)
            {
                swap(a[num],a[end]);
                //num++;
                end--;
            }
            else num++;
           
        }
    }
    
};



//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends