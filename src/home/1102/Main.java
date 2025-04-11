import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if (S1(n) && S2(n)) {
            System.out.print("1 ");
        } else {
            System.out.print("0 ");
        }
        if (S1(n) || S2(n)) {
            System.out.print("1 ");
        } else {
            System.out.print("0 ");
        }
        if (S1(n) ^ S2(n)) {
            System.out.print("1 ");
        } else {
            System.out.print("0 ");
        }
        if (S1(n) || S2(n)) {
            System.out.print("0 ");
        } else {
            System.out.print("1 ");
        }
        sc.close();
    }

    public static boolean S1(int n) {
        return n % 2 == 0;
    }

    public static boolean S2(int n) {
        return (n > 4) && (n <= 12);
    }
}