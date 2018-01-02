=begin
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:
[
  [7],
  [2, 2, 3]
]
=end

# @param {Integer[]} candidates
# @param {Integer} target
# @return {Integer[][]}
def combination_sum(candidates, target)
    sets = []

    candidates.each.with_index do |candidate, index|
        if candidate < target
            sub_solutions = combination_sum(candidates[index..-1], target - candidate)
            sub_solutions.each do |solution|
                sets.push([candidate].concat(solution))
            end
        elsif candidate == target
            sets.push([candidate])
        end
    end
    sets
end
