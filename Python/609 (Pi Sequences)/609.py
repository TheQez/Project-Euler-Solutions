# Alex Slater 609

import math
import time

start = time.time()
limit = 10**8


#Get all primes up to limit
sieve = [True]*(limit+1)
sieve[0] = False
sieve[1] = False
for i in range(2, int(math.sqrt(limit))+1):
    if sieve[i] == True:
        for j in range(2*i, limit+1, i):
            sieve[j] = False
                
primes = [i for i, x in enumerate(sieve) if x]
del sieve
print("Generated primes")


#Too expensive to hold all of pi(x), but holding up to first iteration is small enough to fit in memory.
pi = []
count = 0
for i in range(0, len(primes)+1):
    if i == primes[count]:
        count += 1
    pi.append(count)
print("Generated pi table")


#Find the highest c(u) value possible after the first iteration
maxc = 1
primeSet = set(primes)
del primes
n = len(primeSet)
while n > 1:
    maxc += 1
    n = pi[n]
print("Found maxc")


#Get t, where t(n,k) is the number of sequences starting from n with k non-primes, including sequences with only 1 element
t = [[0 for i in range(0, maxc)] for j in range(0, len(primeSet)+1)]
for i in range(1, len(primeSet)+1):
    if i in primeSet: #This extends t to the next value along the chain, using the previous values. Using sets as they are fast at "in" operations
        t[i][0] += 1
        shift = 0
    else:
        t[i][1] += 1
        shift = 1

    primeCount = pi[i]
    for j in range(0, maxc-1):
        t[i][j+shift] += t[primeCount][j]
print("Generated t(n,k) table")


#Now find all our values of p(n,k)
p = [0 for i in range(0, maxc+1)] #+1 as our maxc is only up to first iteration
primeCount = 0 #Takes the value of pi(i)
for i in range(2, limit+1):
    shift = 1
    if i in primeSet:
        primeCount += 1
        shift = 0 

    for j in range(0, maxc): #If not a prime, shift everything up by 1
        p[j+shift] += t[primeCount][j]
print("Generated p(n,k) values")


answer = 1
for i in p:
    if i != 0:
        answer = (answer * i) % 1000000007

print("P(", limit, ") =" , answer, "(mod 1000000007)")
end = time.time()
print(int(end-start), "seconds elapsed.")
