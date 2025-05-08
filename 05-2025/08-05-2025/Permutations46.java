import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Permutations46 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            int n;
            System.out.print("Enter size: ");
            n = sc.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < nums.length; i++) {
                System.out.print("[" + i + "]: ");
                nums[i] = sc.nextInt();
                sc.nextLine();
            }
            
            List<List<Integer>> res = permute(nums);
            for (List<Integer> i : res) {
                System.out.print("[");
                for (int j : i) {
                    System.out.print(j + ", ");
                }
                System.out.println("]");
            }
            System.out.println("End.");
            String c = sc.nextLine();
            if (c.equalsIgnoreCase("n")) {
                break;
            }
        }
        sc.close();

    }

    public static List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        ArrayList<Integer> path = new ArrayList<>();
        ArrayList<Integer> res_nums = new ArrayList<>();
        for (int i : nums){
            res_nums.add(i);
        }
        backtrack(res, path, res_nums);
        return res;
    }

    public static void backtrack(List<List<Integer>> res, ArrayList<Integer> path, ArrayList<Integer> res_nums) {
        for (int i = 0; i < res_nums.size(); i++) {
            int val = res_nums.get(i);
            res_nums.remove(i);

            path.add(val);
            if (!res_nums.isEmpty()) {
                backtrack(res, path, res_nums);
            } else {
                res.add(new ArrayList<>(path));
            }

            path.remove(path.size() - 1);
            res_nums.add(i, val);
        }
    }

}