using System;

namespace LittleTheoremOfFermat {
    public class  Program {

        static long gcd(long a, long b) {
            if (a < b) return gcd(b, a);
            if (a%b == 0) return b;
            return gcd(b, a%b);
        }

        static long power(long b, long exp, long n) {
            long result = 1;
            b %= n;

            while(exp > 0) {
                if (exp%2 == 1) result = (b*result)%n;
                exp/=2;
                b = (b*b)%n;
            }
            return result;
        }

        static bool LittleTheoremOfFermat(long num) {
            if (num == 3 || num == 2) return true;
            if (num%2 == 0 || num<=1) return false;
            long checks = num < 20 ? num : 20;
            Random rand = new Random();
            for (int i = 0; i<checks; i++) {
                long current = rand.Next()%(num-4)+2;
                if (gcd(num, current) != 1) return false;
                if (power(current, num-1, num) != 1) return false;
            }
            return true;
        }

        static void Main(string[] args) {
            Console.WriteLine("Enter a number to check if it's prime or composite");
            int num = Int32.Parse(Console.ReadLine());
            Console.WriteLine("The number you entered is "+(LittleTheoremOfFermat(num)?"prime":"not prime"));
        }
    }
}
