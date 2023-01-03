#include <iostream>

//a very fast solution that has a time complexity of O(sqrt(n))
bool primalityTest(int num) {
    if (!(num%2)) return num==2;

    for (int i = 3; i*i<=num; i+=2) {
        if (!(num%i)) return false;
    }    
    return true;
}


int main() {
    int num;
    std::cout << "Enter a number to check if it's prime or not.\n";
    std::cin >> num;
    std::cout << "The number you entered is "<<(primalityTest(num) ? "prime" : "not prime")<< "\n";
    return 0;   
}
