#User function Template for python3

class Solution:
    def findTwoElement( self,arr): 
        # code here
        n=len(arr)
        s=set(arr)
        ss=sum(s)
        sk=sum(arr)
        sd=0
        for i in range(n+1):
            sd+=i
        return (sk-ss),(sd-ss)
        
            



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.findTwoElement(arr)
        print(str(ans[0]) + " " + str(ans[1]))
        tc = tc - 1

# } Driver Code Ends