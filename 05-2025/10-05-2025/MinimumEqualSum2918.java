import java.util.Scanner;

public class MinimumEqualSum2918 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {

            int n1, n2;
            System.out.print("Array 1 size: ");
            n1 = sc.nextInt();
            sc.nextLine();
            int[] nums1 = new int[n1];
            for (int i = 0; i < n1; i++) {
                System.out.print("[" + i + "]");
                nums1[i] = sc.nextInt();
                sc.nextLine();
            }
            System.out.print("Array 2 size: ");
            n2 = sc.nextInt();
            sc.nextLine();
            int[] nums2 = new int[n2];
            for (int i = 0; i < n2; i++) {
                System.out.print("[" + i + "]");
                nums2[i] = sc.nextInt();
                sc.nextLine();
            }

            System.out.println("Answer: " + minSum(nums1, nums2));

            String c = sc.nextLine();
            if (c.equalsIgnoreCase("n")) {
                break;
            }
        }
        sc.close();
    }

    public static long minSum(int[] nums1, int[] nums2) {
        long sumA, sumB, cA, cB;
        sumA = sumB = cA = cB = 0;
        int i = 0;
        while (i < nums1.length && i < nums2.length) {
            sumA += nums1[i];
            sumB += nums2[i];

            cA += (nums1[i] == 0) ? 1 : 0;
            cB += (nums2[i] == 0) ? 1 : 0;
            ++i;
        }

        while (i < nums1.length) {
            sumA += nums1[i];
            cA += (nums1[i] == 0) ? 1 : 0;
            ++i;
        }
        while (i < nums2.length) {
            sumB += nums2[i];
            cB += (nums2[i] == 0) ? 1 : 0;
            ++i;
        }

        long x, x1;
        x = sumA + cA;
        x1 = sumB + cB;

        if (x == x1) {
            return x;
        } else if (x < x1) {
            return (cA > 0) ? x1 : -1;
        } else {
            return (cB > 0) ? x : -1;
        }
    }
}