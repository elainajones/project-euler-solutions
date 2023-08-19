
local function get3Multiples(sum, count)  
   if count > 999 then
      return sum
   else return get3Multiples(sum + count, count + 3)
   end
end

local function get5MultiplesSimple(sum, count)  
   if count > 995 then
      return sum
   else return get5MultiplesSimple(sum + count, count + 5)
   end
end
   
local function get5Multiples(sum, count)  
   if count > 995 then
      return sum
   elseif count % 3 ~= 0 then
      return get5Multiples(sum + count, count + 5)
   else 
      return get5Multiples(sum, count + 5)
   end
end
local function getIterativeCount(number)
   return ((number * number) + number) / 2
end
function main()
   print((getIterativeCount(333) * 3) + (getIterativeCount(199) * 5) - (getIterativeCount(66) * 15))
   print(get3Multiples(0, 0))
   print((getIterativeCount(333) * 3))
   print(get5MultiplesSimple(0, 0))
   print((getIterativeCount(199) * 5))

end
main()




