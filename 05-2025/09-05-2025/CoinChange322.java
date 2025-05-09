import java.util.Arrays;
import java.util.Scanner;

public class CoinChange322 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            System.out.print("Amount: ");
            int amount = sc.nextInt();

            System.out.print("Array size: ");
            int size = sc.nextInt();
            int[] coins = new int[size];
            for (int i = 0; i < size; i++) {
                System.out.print("[" + i + "]: ");
                coins[i] = sc.nextInt();
                sc.nextLine();
            }

            System.out.println("Answer: " + coinChange(coins, amount) );

            String c = sc.nextLine();
            if (c.equalsIgnoreCase("n")) {
                break;
            }
        }
        sc.close();
    }

    public static int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        for (int i = 1; i < amount + 1; i++) {
            for (int coin : coins) {
                if (i - coin >= 0 && dp[i - coin] != Integer.MAX_VALUE) {
                    dp[i] = Integer.min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return (dp[amount] == Integer.MAX_VALUE) ? -1 : dp[amount];
    }
}
