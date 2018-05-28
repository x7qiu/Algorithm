#!/usr/bin/env python

# Given an array of integers, return indices of the two numbers such that they add up to a specific target.
# You may assume that each input would have exactly one solution, and you may not use the same element twice.

# Example
# Given nums = [2, 7, 11, 15], target = 9, return [0,1]



# Time: O(nlogn)
# Space: O(n)
class Solution1(object):
    """sort the array, then loop through each element finding the complement using Binary search,
    and loop through the original array to find their index
    """
    pass

# two-pass hashtable
# Time: O(n)
# Space: O(n)
class Solution2(object):
    def twoSum(self, nums, target):
        d = {}
        for (i, v) in enumerate(nums):
            if v in d:
                d[v].append(i)
            else:
                d[v] = [i]

        for val in d:
            want = target - val
            if want in d:
                if want == val and len(d[want]) == 1:
                    return  
                if want == val and len(d[want]) == 2:
                    return d[want]
                else:
                    ans = d[val]
                    ans.extend(d[want])
                    return ans

# one-pass hashtable
# Time: O(n)
# Space: O(n)              
class Solution3(object):
    def twoSum(self, nums, target):
        d = {}
        for (index, val) in enumerate(nums):
            want = target - val
            if want in d:
                return [d[want],index]
            else:
                d[val] = index            




if __name__ == "__main__":
    #S1 = Solution1()
    S2 = Solution2()
    S3 = Solution3()
    #print S1.twoSum([2,7,11,15], 9)
    print S2.twoSum([2,7,11,15], 9)
    print S3.twoSum([2,7,11,15], 9)
    print 

    
    #print S1.twoSum([2,2,11,15], 4)
    print S2.twoSum([2,2,11,15], 4)
    print S3.twoSum([2,2,11,15], 4)
    print

    #print S1.twoSum([2,3,11,15], 4)
    print S2.twoSum([2,3,11,15], 4)
    print S3.twoSum([2,3,11,15], 4)
    print

    #print S1.twoSum([3,2,4], 6)
    print S2.twoSum([3,2,4], 6)
    print S3.twoSum([3,2,4], 6)
    print

    #print S1.twoSum([3,2], 6)
    print S2.twoSum([3,2], 6)
    print S3.twoSum([3,2], 6)
    print

    #print S1.twoSum([3,2,3], 6)
    print S2.twoSum([3,2,3], 6)
    print S3.twoSum([3,2,3], 6)

