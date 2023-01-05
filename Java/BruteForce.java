import java.util.Scanner;

public class Main {
    public static boolean isPrime(int num) {
        if (num <= 1) return false;
        if (num == 2) return true;
        for (int i = 2; i<num; i++)
            if (num%i==0)
                return false;
        return true;
    }

    public static void main(String[] args) {
        System.out.println("Enter a number to check if it's prime or composite");
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();
        System.out.println("The number you entered is "+(isPrime(num)?"prime":"not prime"));
    }
}
