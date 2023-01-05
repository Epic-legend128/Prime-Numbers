import java.util.Scanner;

public class Main {
    public static boolean PrimalityTest(int num) {
        if (num <= 1) return false;
        if (num%2 == 0) return num==2;
        for (int i = 3; i*i<=num; i+=2)
            if (num%i==0)
                return false;
        return true;
    }

    public static void main(String[] args) {
        System.out.println("Enter a number to check if it's prime or composite");
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();
        System.out.println("The number you entered is "+(PrimalityTest(num)?"prime":"not prime"));
    }
}
