//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

static bool comp(const pair<int,int>&a ,const pair<int,int>&b)
{
    return a.second<b.second;
}
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int n,int start[], int end[])
    {
        int c=1;
        vector<pair<int,int>>k;
        for(int i=0;i<n;i++)
        {
            k.push_back({start[i],end[i]});
        }
        sort(k.begin(),k.end(),comp);
        int pre=k[0].second;
        /*for (int j=0;j<n;j++)
        {
            cout<<k[j].first<<" "<<k[j].second<<endl;
        }*/
        for(int i=1;i<n;i++)
        {
            if(k[i].first>pre)
            {
                c++;
                pre=k[i].second;
            }
        }
        return c;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends