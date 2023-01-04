import random

def gcd(a, b):
    if a < b:
        a, b = b, a
    if a%b == 0:
        return b
    return gcd(b, a%b)

def power(base, exp, n):
    result = 1
    base%=n
    while(exp > 0):
        if (exp%2 != 0):
            result = (base*result)%n
        exp=int(exp/2)
        base=(base*base)%n
    return result

def little_theorem_of_fermat(num):
    if num == 3 or num==2:
        return True
    if num <= 1 or num%2 == 0:
        return False
    
    checks = 20 if num > 20 else num
    for i in range(0, checks):
        current = random.randint(2, num-3)
        if gcd(num, current) != 1:
            return False
        if power(current, num-1, num) != 1:
            return False
    return True


test = int(input("Enter a number to check if it's prime or composite: "))
print("The number is "+("prime" if little_theorem_of_fermat(test) else "not prime"))
