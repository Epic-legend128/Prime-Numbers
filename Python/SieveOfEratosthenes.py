def sieve_eratosthenes(lower, upper):
    primes = []
    is_prime = []
    for i in range(0, upper+1):
        is_prime.append(True)
    is_prime[0], is_prime[1] = False, False

    for i in range(2, upper+1):
        if is_prime[i]:
            for j in range(i*2, upper+1, i):
                is_prime[j] = False
            if i >= lower:
                primes.append(i)
    return primes


print("This method finds all prime numbers between a range")
lower = int(input("Enter the lower bound of the range: "))
upper = int(input("Enter the upper bound of the range: "))
primes = sieve_eratosthenes(lower, upper)
print("A list of all of the primes is the following:")
print(", ".join(map(str, primes)))
