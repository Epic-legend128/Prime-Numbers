#include <iostream>

//takes in a number and returns true if it is prime and false otherwise, worst possible solution with O(N) time notation
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    for (int i = 2; i<num; i++) {
        if (!(num%i)) return false;
    }
    return true;
}


int main() {
    int num;
    std::cout << "Enter a number to check if it's prime or not.\n";
    std::cin >> num;
    std::cout << "The number you entered is "<<(isPrime(num) ? "prime" : "not prime")<< "\n";
    return 0;
}
