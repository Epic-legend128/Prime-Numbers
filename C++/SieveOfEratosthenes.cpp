#include <iostream>
#include <vector>

//takes as arguments the lower and upper bounds of a certain range and returns a vector with all prime numbers within the given range
std::vector<int> sieve_of_eratosthenes(const int lower, const int upper) {
    std::vector<int> primes;
    std::vector<bool> is_prime(upper+1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i<=upper; i++) {
        if (is_prime[i]) {
            for (int j = i*2; j<=upper; j+=i) {
                is_prime[j] = false;
            }
            if (i >= lower) primes.push_back(i);
        }
    }
    return primes;
}

int main() {
    int lower, upper;
    std::cout << "This method finds all prime numbers between a range\n";
    std::cout << "Enter the lower bound of the range\n";
    std::cin >> lower;
    std::cout << "Enter the upper bound of the range\n";
    std::cin >> upper;
    if (lower > upper) std::swap(lower, upper);
    
    std::vector<int> primes = sieve_of_eratosthenes(lower, upper);
    
    if (primes.size() > 0) {
        std::cout << "A list of all the prime numbers found within the given range:\n";
        bool first = true;
        for (int x: primes) {
            if (!first) std::cout << ", ";
            else first = false;
            std::cout << x;
        }
        std::cout << "\n";
    }
    else {
        std::cout << "No prime numbers found within the given range\n";
    }
    return 0;
}
