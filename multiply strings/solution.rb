=begin
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
=end



# @param {String} num1
# @param {String} num2
# @return {String}

## lets do it like we learned in elementary school, right to left with a carry
## this will meet the requirements of not converting the strings, and handle the huge numbers nicely
    def multiply(num1, num2)
        return '0' if num1 == '0' || num2 == '0'
        result = []
        placeValue2 = 1
        
        index1 = num1.length - 1
        while index1 >= 0
           carry = 0
           index2 = num2.length - 1
           component = []
           while index2 >= 0
               product = num1[index1].to_i * num2[index2].to_i + carry
               carry = (product/ 10).floor
               component.unshift product % 10
               index2 -= 1
           end
           component.unshift carry if carry != 0
           addArrs!(result, component, num1.length - 1 - index1)
           index1 -= 1
        end
        result.join
    end
    
    def addArrs!(arr1, arr2, arr2LeftShift)
        index1 = arr1.length - 1 - arr2LeftShift
        index2 = arr2.length - 1
        
        carry = 0
        while index2 >= 0
            if index1 >= 0
               sum = arr1[index1] + arr2[index2] + carry
               arr1[index1] = sum % 10
            else
                sum = arr2[index2] + carry
                arr1.unshift sum % 10
            end 
            carry = sum > 9 ? 1 : 0
            index1 -= 1
            index2 -= 1
        end
        arr1.unshift carry if carry > 0
    end
    