#!/bin/bash python
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        left = 0
        right = len(height) - 1
        max_value = 0
        while left < right:
            max_value = max(max_value, min(height[left], height[right]) * (right - left))
            if height[left] <= height[right]:
                left += 1
            else:
                right -= 1
        return max_value

if __name__ == "__main__":
    s = Solution()
    # lowest
    sample_input = [1,8,6,2,5,4,8,3,7]
    print(s.maxArea(sample_input))

    sample_input = [1, 8, 1, 10000, 9, 8,1]
    print(s.maxArea(sample_input))