import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static ArrayList<Integer> SieveOfEratosthenes(int lower, int upper) {
        boolean[] isPrime = new boolean[upper+1];
        for (int i = 2; i<=upper; i++) {
            isPrime[i] = true;
        }
        isPrime[0] = false; isPrime[1] = false;
        ArrayList<Integer> primes = new ArrayList<Integer>();
        for (int i = 2; i<=upper; i++) {
            if (isPrime[i]) {
                for (int j = i+i; j<=upper; j+=i) {
                    isPrime[j] = false;
                } 
               if (i >= lower) primes.add(i);
            }
        }
        return primes;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("This method finds all prime numbers between a range");
        System.out.println("Enter the lower bound of the range");
        int lower = input.nextInt();
        System.out.println("Enter the lower bound of the range");
        int upper = input.nextInt();
        ArrayList<Integer> primes = SieveOfEratosthenes(lower, upper);
        System.out.println("A list of all of the prime numbers between the given range:");
        System.out.print(primes.get(0));
        for (int i = 1; i<primes.size(); i++) {
            System.out.print(", "+primes.get(i));
        }
    }
}
