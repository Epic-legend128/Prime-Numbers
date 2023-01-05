using System;

namespace BruteForce {
    public class  Program {
        static bool IsPrime(int num) {
            if (num <= 1) return false;
            if (num == 2) return true;
            for (int i = 2; i<num; i++) {
                if (num%i == 0)
                    return false;
            }
            return true;
        }

        static void Main(string[] args) {
            Console.WriteLine("Enter a number to check if it's prime or composite");
            int num = Int32.Parse(Console.ReadLine());
            Console.WriteLine("The number you entered is "+(IsPrime(num)?"prime":"not prime"));
        }
    }
}
