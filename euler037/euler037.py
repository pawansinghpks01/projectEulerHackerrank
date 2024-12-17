primes = []

def isprime(n):
    return all([(n % j) for j in range(2, int(n**0.5)+1)]) and n>1
def SieveOfEratosthenes(n):
    prime = [True for i in range(n+1)]
    p = 2
    while (p * p <= n):
        if (prime[p] == True):
            for i in range(p * 2, n+1, p):
                prime[i] = False
        p += 1
    for p in range(23, n):
        if prime[p]:
            primes.append(p)
SieveOfEratosthenes(1000000)
sm = 0
n = int(input())
t = 0
while(t<len(primes) and primes[t]<=n):
    flag = 1
    s = str(primes[t])
    for i in range(1,len(s)):
        if not isprime(int(s[:-i])):
            flag=0
            break
    if flag==1:
        for i in range(1,len(s)):
            if not isprime(int(s[-i:])):
                flag=0
                break
    if flag==1:
        sm+=int(s)
    t+=1
print(sm)
