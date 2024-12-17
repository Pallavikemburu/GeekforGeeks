#User function Template for python3


class Solution:

    def aggressiveCows(self, stalls, k):
        pass
        stalls.sort()
        n=len(stalls)
        if(k==2 or k==1):
            return stalls[n-1]-stalls[0]
        l=1
        r=stalls[n-1]-stalls[0]
        mid=l+(r-l)//2
        ans=[]
        while(l<=r):
            mid=l+(r-l)//2
            cnt=1
            j=0
            for i in range(1,n):
                if(stalls[i]-stalls[j]>=mid):
                    j=i
                    cnt+=1
            if(cnt>=k):
                ans.append(mid)
                l=mid+1
            else:
                r=mid-1
        if(len(ans)==0):
            return 0
        return ans[-1]





#{ 
 # Driver Code Starts
#Initial Template for Python 3
import bisect
#Main
if __name__ == '__main__':
    t = int(input())
    while t:
        t -= 1
        A = [int(x) for x in input().strip().split()]
        nd = [int(x) for x in input().strip().split()]
        D = nd[0]
        ob = Solution()
        ans = ob.aggressiveCows(A, D)
        print(ans)
        print("~")
# } Driver Code Ends