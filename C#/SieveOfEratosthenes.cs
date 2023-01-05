using System;
using System.Collections.Generic;

namespace SieveOfEratosthenes {
    public class  Program {
        static List<int> SieveOfEratosthenes(int lower, int upper) {
            bool[] IsPrime = new bool[upper+1];
            for (int i = 0; i<=upper; i++) {
                IsPrime[i] = true;
            }
            IsPrime[0] = false;
            IsPrime[1] = false;

            List<int> Primes = new List<int>();
            for (int i = 2; i<=upper; i++) {
                if (IsPrime[i]) {
                    for (int j = i*2; j<=upper; j+=i) {
                        IsPrime[j] = false;
                    }
                    if (i >= lower) Primes.Add(i);
                }
            }
            return Primes;
        }

        static void Main(string[] args) {
            Console.WriteLine("This method finds all prime numbers between a range");
            Console.WriteLine("Enter the lower bound of the range");
            int lower = Int32.Parse(Console.ReadLine());
            Console.WriteLine("Enter the upper bound of the range");
            int upper = Int32.Parse(Console.ReadLine());
            List<int> Primes = SieveOfEratosthenes(lower, upper);
            Console.WriteLine("A list of all of the prime numbers you entered is the following:");
            Console.WriteLine(String.Join(", ", Primes));
        }
    }
}
