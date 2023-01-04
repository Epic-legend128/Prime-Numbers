def primality_test(num):
    if num <= 1:
        return False
    if num%2 == 0:
        return num==2
    i = 3
    while(i*i<=num):
        if num%i == 0:
            return False
        i+=2
    return True

test = int(input("Enter a number to check if it's prime or composite: "))
print("The number is "+("prime" if primality_test(test) else "not prime"))
