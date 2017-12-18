# This uses a slightly improved brute force method that checks to see if a mountain is already blocked by a previously checked 'pivot' mountain to reduce the number of required operations
import math
import time

start_time = time.clock()

'''
primes = [2]
n = 50000
for i in range (3, 2*int(n * ( math.log(n) + math.log(math.log(n)) ))): #This will give at least 2n primes
    limit = math.sqrt(i)
    for j in primes:
        if j > limit:
            isPrime = True
            break
        elif i % j == 0:
            isPrime = False
            break
    if isPrime:
        primes.append(i)
        if len(primes) >= 2*n:
            print(i)
            break
'''

#Sieve of eratosthenes method
n = 2500000
max = 2*int(n * (math.log(n) + math.log( math.log(n) )))
primes = []
numbers = [True]*(max+1)
numbers[0] = False
numbers[1] = False
for p in range(2, len(numbers)):
    if numbers[p] == True:
        primes.append(p)
        for i in range(2, int(len(numbers)/p)):
            numbers[i*p] = False
        
print("Primes generated")

height = [primes[0]]
for i in range (1,n):
    height.append(height[i-1] - primes[2*i - 1] + primes[2*i])

print("Heights generated")

distance = [primes[0]]
for i in range (1,n):
    distance.append(distance[i-1] + primes[2*i - 1] + primes[2*i])

print("Distances generated")

'''
hillVisibleMax = 0
hillVisible = []
hillVisible.append(0)
for i in range(1,n):
    hillCurrent = i
    hillCurrentVisible = 0
    bestGrad = (height[hillCurrent] - height[hillCurrent-1]) / (distance[hillCurrent] - distance[hillCurrent-1])
    #print(bestGrad)
    hillCurrentVisible += 1
    for j in range(2, hillCurrent+1):
        currentGrad = (height[hillCurrent] - height[hillCurrent-j]) / (distance[hillCurrent] - distance[hillCurrent-j])
        #print(currentGrad)
        if currentGrad < bestGrad:
            hillCurrentVisible += 1
            bestGrad = currentGrad
            #print("Incremented due to hill:" , hillCurrent-j)
    #print("Hill:" , hillCurrent , " sees: " , hillCurrentVisible)
    hillVisible.append(hillCurrentVisible)
'''


hillPivot = 0
hillPivotVisible = 0
hillPivotTable = []
hillVisible = []
hillVisible.append(0)
for i in range (1,n):
    hillCurrent = i
    hillCurrentVisible = 0
    bestGrad = 100

    #Brute force all hills up to and including the pivot
    for j in range(1, hillCurrent+1-hillPivot):
        currentGrad = (height[hillCurrent] - height[hillCurrent-j]) / (distance[hillCurrent] - distance[hillCurrent-j])
        if currentGrad < bestGrad:
            hillCurrentVisible += 1
            bestGrad = currentGrad
            #print("Incremented before pivot due to hill:" , hillCurrent-j)

    #Use the pivot table to get the hills we need to brute force
    pivotGrad = (height[hillCurrent]-height[hillPivot]) / (distance[hillCurrent] - distance[hillPivot])
    pivotTableEnd = len(hillPivotTable) #In case that all gradients are less
    hillPotentialList = []
    for j in range(0, len(hillPivotTable)):
        #print("Potential visible hill: ", hillPivotTable[j][0] , " (disregard last)")
        if pivotGrad > hillPivotTable[j][1]:
            hillPotentialList.append(hillPivotTable[j][0])
        else:
            break

    #Brute force all the hills we need to
    hillPotentialList.sort(reverse=True)
    for j in range(0, len(hillPotentialList)):
        #print("Trying hill:" , hillPotentialList[j] , " after the pivot")
        currentGrad = (height[hillCurrent] - height[hillPotentialList[j]]) / (distance[hillCurrent] - distance[hillPotentialList[j]])
        if currentGrad < bestGrad:
            hillCurrentVisible += 1
            bestGrad = currentGrad
            #print("Incremented after pivot due to hill:" , hillPotentialList[j])

    #Generate a new pivot if we want to
    if hillCurrentVisible >= hillPivotVisible * (1 - (hillCurrent-hillPivot)/10000): #Find if this new hill makes a good next pivot
        hillPivot = hillCurrent
        hillPivotVisible = hillCurrentVisible
        print("New pivot at hill: " , hillCurrent, " , sees: " , hillCurrentVisible)

        #Generate our new pivot table
        hillPivotTable = []
        for j in range(1, hillPivot+1):
            g = (height[hillPivot] - height[hillPivot-j]) / (distance[hillPivot] - distance[hillPivot-j])
            hillPivotTable.append((hillPivot-j, g))
        hillPivotTable.sort(key=lambda tup: tup[1])

    #print("Hill: " , hillCurrent , " , sees: " , hillCurrentVisible)
    hillVisible.append(hillCurrentVisible)


print("Hills visible generated")

#print(hillVisible)

sum = 0
for i in range(0, n):
    sum += hillVisible[i]

print("Sum generated") #Efficient enough

print(sum)

print(time.clock() - start_time , " seconds")

file = open('output.txt', 'w')
file.write(str(sum))
file.close()
