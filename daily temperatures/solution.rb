=begin
Given a list of daily temperatures, produce a list that, for each day in the input,
 tells you how many days you would have to wait until a warmer temperature.
  If there is no future day for which this is possible, put 0 instead.

For example, given the list temperatures = [73, 74, 75, 71, 69, 72, 76, 73],
your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000].
Each temperature will be an integer in the range [30, 100].
=end

=begin
my pseudocode

loop through array

fill soution with 0s

if stack is empty or item is less than top:
  push index to stack

if greater than top of stack:
  pop off elements
  solution[popped_idx] = current_idx - popped_idx
  push the item

Each element gets pushed and popped at most once,
so this is an O(n) solution
=end

# @param {Integer[]} temperatures
# @return {Integer[]}
def daily_temperatures(temperatures)
    solution = Array.new(temperatures.length){0}
    stack = [];
    temperatures.each.with_index do |temp, idx|
        if stack.empty? || temperatures[stack.last] >= temp
            stack.push idx
        else
            until stack.empty? || temperatures[stack.last] >= temp
                popped_idx = stack.pop
                solution[popped_idx] = idx - popped_idx
            end
            stack.push idx
        end
    end
    solution
end
