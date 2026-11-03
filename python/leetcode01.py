from typing import List

class Solution01:
    def search(self, nums: list[int], target: int) -> int:
        left,right = 0, len(nums) - 1
        while left <= right :
            mid = (left + right) // 2
            if nums[mid] < target :
                left = mid + 1
            elif nums[mid] > target :
                right = mid - 1
            else :
                return mid
        return -1
    
class Solution02:
    def removeElement(self, nums: list[int], val: int) -> int:
        i = 0
        for j in range(len(nums)) :
            if nums[j] != val :
                nums[i] = nums[j]
                i+= 1
        return i

class Solution03:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        record = []
        for i in nums :
            record.append(i * i)
        record.sort()
        return record