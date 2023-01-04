# Prime-Numbers
Different methods of finding prime numbers in a multitude of languages.
<br>
Here you will find 4 different methods of checking whether a number is prime or not.

# Brute Force
This method checks every positive integer bigger than 1 and less than the number we are running the primality check on. If it meets a number that divides our targeted number without leaving any remainder the program will stop as it has found out that the number is composite. If it finds none such example it will return true meaning the number is prime.
<br>
The time notation of this algorithm is <b>O(n)</b> where n is the number that is being checked.

# Custom Solution
This solution is quite fast but in the end it is an optimised version of the brute force solution described above.
<br>
It first checks if the number is even by checking its remainder with the number 2 and then it starts checking if our target number has a divisor starting from 3 all the way to the sqrt(n) with a step of 2, where n is the target number. The step is 2 so that we can avoid all even numbers as we know all of them are composite. Furthermore, it only checks up until the square root of n as it has been proven that every composite number has at least 1 divisor before its square root.
<br>
This algorithm's time notation is <b>O(n^(1/2))</b> where n is the number that is being checked.

# Sieve of Eratosthenes
The Sieve of Eratosthenes is method used to discover all prime numbers within a given range.
<br>
It works by creating an array with a size of the upper bound plus 1. Then it marks all those numbers as primes. After that it uses a loop starting from 2 and crossing out all of its multiples as prime numbers in the array. It goes on picking the next prime number in the array and marking all its multiples off the array and so on and so forth until it reaches the upper bound of the range. Finally, it outputs all the numbers in the array that remained marked as prime numbers and that are bigger than the lower bound of the range.
<br>
The time notation of this algorithm is <b>O(nlog(log(n)))</b> where n is the number that is being checked.

# Fermat's Little Theorem
This method is the fastest out of all of the ones mentioned in this article, however it doesn't have a 100% success rate. It takes advantage of Fermat's Little Theorem which states that for any prime number p and an integer, a, which is a relative prime to p then the following will be true:
a^(p-1) ≡ 1 (mod p)
What we do is that we check if this equality holds true for many different random values of a where 1 < a < p-1 and a not a divisor of p. If the equality holds true then number p is probably a prime. The more tests you do the more sure you are that your result is correct.
<br>
The time notation that this algorithm has is <b>O(klogn)</b> where k is the amount of checks you make and n is the number you are checking.
