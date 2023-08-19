local function fibonacci(one, two)
   return one + two 
end

local function cameronSolution()
   local sum = 0
   local numbers = {1, 2}
   local i = 1
   repeat
      numbers[i + 2] = fibonacci(numbers[i], numbers[i + 1])
      if numbers[i] % 2 == 0 then
         sum = sum + numbers[i]
      end
      i = i + 1
   until numbers[i + 1] > 4000000
   print(sum)
end

local function jackSolution(first, second, sum, last)
   if (second > last) then
      return sum
   end
   sum = sum + second;
   local third = first + second;
   local fourth = second + third;
   local fifth = third + fourth;
   return jackSolution(fourth, fifth, sum, last)
end

local function main()
   cameronSolution()
   print(jackSolution(1, 2, 0, 4000000))
   
end
main()
