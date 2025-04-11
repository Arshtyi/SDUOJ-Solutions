import java.util.Scanner;

public class Main {
    public static final int MOD = 11;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String f = sc.nextLine();
        String s = f.replace("-", "");
        int sum = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            sum = (sum % MOD + (Integer.parseInt(s.substring(i, i + 1)) * (i + 1)) % MOD) % MOD;
        }
        char c = (sum == 10) ? 'X' : (char) (sum + '0');
        if (c == s.charAt(s.length() - 1)) {
            System.out.println("Right");
        } else {
            System.out.println(f.substring(0, f.length() - 1) + c);
        }
        sc.close();
    }
}