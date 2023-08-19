# PROBLEM 10
#
# The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
#
# Find the sum of all the primes below two million.
#
# Duration: 22.68 minutes
# Duration on server: 13.21 minutes
primes = [2,3]
x=0
for t in range(2,2000001):
    for p in primes:
        if t % p == 0:
            break
        elif p > int(t/primes[x]):
            break
    if t % p != 0:
        primes.append(t)
    elif t >= primes[x]*primes[x+1]:
        x+=1

print(f"Sum of primes:\t{sum(primes)-3}")
