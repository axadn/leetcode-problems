=begin
You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
Note:
All elements in nums1 and nums2 are unique.
The length of both nums1 and nums2 would not exceed 1000.
=end

=begin
 by feeding nums1 into a hash map
 and analyzing nums2 using a min stack,
 I can achieve O(n + m) time
=end

# @param {Integer[]} find_nums
# @param {Integer[]} nums
# @return {Integer[]}
def next_greater_element(find_nums, nums)
    solution = Array.new(find_nums.length){-1}
    index_map = Hash.new
    find_nums.each.with_index do |num, idx|
        index_map[num] = idx
    end

    stack = []
    nums.each do |num|
        if stack.empty? || num <= stack.last
            stack.push num
        else
           until stack.empty? || num <= stack.last
               popped_item = stack.pop
               if index_map[popped_item]
                   solution[index_map[popped_item]] = num
               end
           end
           stack.push num
        end
    end
    solution
end
