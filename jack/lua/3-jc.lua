
function getSmallestFactor(number)
   for i = 2, number do
      if number % i == 0 then
         return i
      end
   end
   return number
end

function isPrime(number)
   return (number == getSmallestFactor(number))
end

function getFactors(number)
   local factors = {}
   repeat
      local factor = getSmallestFactor(number)
      for _, v in pairs(factors) do
         if v == factor then
            factor = nil
            break
         end
      end
      table.insert(factors, factor)
      number = number / factor
   until number == 1

   return factors
end

local function camSolution(max)
   local factors = getFactors(max)
   local largest = 0
   for _, v in pairs(factors) do
      if v > largest and isPrime(v) then
         largest = v
      end
   end
   return largest
end

local function jackSolution(count, number)
   if (number % count == 0) then
      if (isPrime(number / count)) then
         return (number / count)
      end
   end 
   return jackSolution(count + 1, number)
end

function main()
    print("Prime factors of 13195: " .. camSolution(13195))
    print("Prime factors of 600851475143: " .. camSolution(600851475143))
    print(jackSolution(2, 13195))
    print(jackSolution(2, 600851475143))

end
main()
