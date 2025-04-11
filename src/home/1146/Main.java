import java.util.Scanner;

public class Main {
    public final static int N = 100 + 10;
    public static int[] nums = new int[N];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- != 0) {
            int n = sc.nextInt();
            for (int i = 1; i <= n; i++) {
                nums[i] = sc.nextInt();
            }
            int cnt = 0;
            for (int i = 2; i < n; i++) {
                if ((nums[i - 1] < nums[i] && nums[i] > nums[i + 1])
                        || (nums[i - 1] > nums[i] && nums[i] < nums[i + 1])) {
                    cnt++;
                }
            }
            System.out.println(cnt);
        }
        sc.close();
    }
}