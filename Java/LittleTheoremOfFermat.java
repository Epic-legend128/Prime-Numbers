import java.util.Scanner;
import java.util.Random;

public class Main {
    public static long gcd(long a, long b) {
        if (a < b) return gcd(b, a);
        if (a%b==0) return b;
        return gcd(b, a%b);
    }

    public static long power(long base, long exp, long n) {
        long result = 1;
        base %= n;
        while (exp > 0) {
            if (exp%2==1) result = (result*base)%n;
            exp/=2;
            base=(base*base)%n;
        }
        return result;
    }

    public static boolean LittleTheoremOfFermat(long num) {
        if (num==2 || num==3) return true;
        if (num <= 1 || num%2 == 0) return false;
        final long CHECKS = num<20 ? num : 20;
        Random rand = new Random();
        for (int i = 0; i<CHECKS; i++) {
            long current = rand.nextLong(num-4)+2;
            if (gcd(num, current) != 1) return false;
            if (power(current, num-1, num) != 1) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println("Enter a number to check if it's prime or composite");
        Scanner input = new Scanner(System.in);
        long num = input.nextInt();
        System.out.println("The number you entered is "+(LittleTheoremOfFermat(num)?"prime":"not prime"));
    }
}
