def isPrime(num):
    if num <= 1:
        return False
    elif num==2:
        return True
    for i in range(2, num):
        if num%i == 0:
            return False
    return True

test = int(input("Enter a number to check if it's prime or composite: "))
print("The number is "+("prime" if isPrime(test) else "not prime"))
