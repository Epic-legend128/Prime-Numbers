using System;

namespace CustomSolution {
    public class  Program {
        static bool PrimalityTest(int num) {
            if (num%2 == 0) return num==2;
            if (num <= 1) return false;
            for (int i = 3; i*i<=num; i+=2) {
                if (num%i == 0)
                    return false;
            }
            return true;
        }

        static void Main(string[] args) {
            Console.WriteLine("Enter a number to check if it's prime or composite");
            int num = Int32.Parse(Console.ReadLine());
            Console.WriteLine("The number you entered is "+(PrimalityTest(num)?"prime":"not prime"));
        }
    }
}
