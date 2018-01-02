=begin
Given a collection of candidate numbers (C) and a target number (T),
 find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
=end
# @param {Integer[]} candidates
# @param {Integer} target
# @return {Integer[][]}
def combination_sum2(candidates, target)
    candidate_counts = Hash.new 0
    candidates.each {|cand| candidate_counts[cand] += 1}
    candidate_counts_arr = []
    candidate_counts.each {|cand, count| candidate_counts_arr.push [cand, count]}
    combination_sum2_step(candidate_counts_arr, 0, target)
end

def combination_sum2_step(candidate_counts, start_idx, target)
    sets = []
    start_idx.upto(candidate_counts.length - 1) do |idx|
        candidate = candidate_counts[idx][0]
        num_occurences = candidate_counts[idx][1]

        if candidate == target
            sets << [candidate]
        else
            sum = candidate
            count = 0
            while count < num_occurences && sum <= target
                if sum == target
                    solution = []
                    (count + 1).times {solution.unshift candidate}
                    sets.push solution
                end

                sub_solutions = combination_sum2_step(
                    candidate_counts, idx + 1, target - sum)
                sub_solutions.each do |solution|
                    (count + 1).times {solution.unshift candidate}
                    sets.push solution
                end
                sum += candidate
                count += 1
            end
        end
    end
    sets
end
