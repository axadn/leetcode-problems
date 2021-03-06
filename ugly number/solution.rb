=begin
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.

=end



# @param {Integer} num
# @return {Boolean}
def is_ugly(num)
    return false if num <= 0
    prime_factors(num).all? {|key, val| key <= 5}
end

def prime_factors(num)
    result = {}
    Math.sqrt(num).floor.downto(2) do |test_factor|
        if num % test_factor == 0
            prime_factors(test_factor).each do |key, val|
                result[key] = true
            end
            prime_factors(num / test_factor).each do |key, val|
                result[key] = true
            end
            break
        end
    end
    result[num] = true if result.empty?
    result
end
