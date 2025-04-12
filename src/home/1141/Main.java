import java.util.Scanner;

public class Main {
    public static final int MOD = 10;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T, n, m;
        T = sc.nextInt();
        while (T-- > 0) {
            n = sc.nextInt();
            m = sc.nextInt() + 1;
            int ans = 1;
            for (int i = m; i <= n; i++) {
                ans = (ans * (i % MOD)) % MOD;
                if (ans == 0)
                    break;
            }
            System.out.println(ans);
        }
        sc.close();
    }
}