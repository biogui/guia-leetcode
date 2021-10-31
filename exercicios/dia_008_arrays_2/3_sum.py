class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        triplets = list()
        nums.sort()
        for i, n in enumerate(nums):
            comp = -n
            
            start = i + 1
            end = len(nums) - 1
            while start < end:
                summ = nums[start] + nums[end]
                if summ == comp and not [n, nums[start], nums[end]] in triplets:
                    triplets.append([n, nums[start], nums[end]])
                    start += 1
                    end -= 1
                elif summ < comp:
                    start += 1
                else:
                    end -= 1
                    
        return triplets