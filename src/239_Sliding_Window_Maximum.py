import heapq
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        win = [(-nums[i], i) for i in range(k)]
        heapq.heapify(win)
        ans = [-win[0][0]]
        for i in range(k,n):
            heapq.heappush(win,(-nums[i],i))
            while win[0][1] <= i - k:
                heapq.heappop(win)
            ans.append(-win[0][0])
        return ans
