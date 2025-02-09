import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if (n == 0 || n == 1) {
            System.out.println("Today, I ate " + n + " apple.");
        } else {
            System.out.println("Today, I ate " + n + " apples.");
        }
        sc.close();
    }
}