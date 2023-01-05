#include <iostream>
#include <cmath>
#include <random>

//gcd
long long gcd(long long a, long long b) {
    if (a<b) std::swap(a, b);
    if (!(a%b)) return b;
    return gcd(b, a%b);
}

//power, (base^exp)%n
long long power(long long base, long long exp, long long n) {
    long long result = 1;
    base %= n;

    while(exp > 0) {
        if(exp & 1) result=(result*base)%n;
        exp>>=1;
        base=(base*base)%n;
    }
    return result;
}

//a very fast way to check if a number is prime but it doesn't have a 100% propability of success, works best with not very big inputs, O(klogn) time notation
bool little_theorem_of_fermat(const long long num) {
    if (num==3||num==2) return true;
    else if (num<=1 || num%2==0) return false;

    const int checks = num < 20 ? num : 20;
    for (int i = 0; i<checks; i++) {
        long long current = rand()%(num-4)+2;
        if (gcd(num, current) != 1) return false;
        if (power(current, num-1, num) != 1) return false;
    }

    return true;
}

int main() {
    long long num;
    std::cout << "Enter a number to check if it's prime or not.\n";
    std::cin >> num;
    std::cout << "The number you entered is "<<(little_theorem_of_fermat(num) ? "prime" : "not prime")<< "\n";
    return 0;
}
