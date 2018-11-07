#Runs in about 10 minutes, could potentially be made faster by using arrays instead of lists

r = 40000000 #The range of numbers
chainLen = 25 #The chain length we are selecting for


#Generates the primes up to r using a Sieve of Eratosthenes method
primes = [i for i in range(2,r+1)]

for i in range (2, r+1):
    if i != 0:
        for j in range(2*i, r+1, i):
            primes[j-2] = 0 #As jth position represents the j+2th number

primes[:] = (n for n in primes if n != 0)


#Generates a list containing the values of the totient function up to r
#Uses t(p^k) = p^k - p^(k-1) for p prime and t(ab) = t(a)t(b) for a,b coprime to generate
totient = [0 for i in range(0, r+1)]
totient[0] = 0
totient[1] = 1

#Fill in the list for all prime powers
for p in primes:
    for i in range(1, r):
        if p**i > r:
            break
        totient[p**i] = p**i - p**(i-1)

#Fill in the gaps using t(ab) = t(a)t(b)
for i in range(1, r+1):
    if totient[i] == 0: #Something we havent covered yet
        for p in primes:
            if i % p == 0: #Find a prime its divisible by
                for j in range(2, r+1):
                    if i % p**j != 0: #Find the maximum power its divisible by
                        totient[i] = totient[p**(j-1)] * totient[int(i/(p**(j-1)))] #By coprime multiplicivity
                        break
                break

#Generate a list containing the length of the totient chain from each n
chains = [0 for i in range(0, r+1)]
chains[1] = 1
for i in range(2, r+1):
    chains[i] = chains[totient[i]] + 1

#Sum all the prime starting points of chains with length chainLen
s = 0
for p in primes:
    if chains[p] == chainLen:
        s += p

print("Sum: ", s)
