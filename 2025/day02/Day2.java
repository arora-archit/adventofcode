import java.util.*;

public class Day2 {
  public static long checkRepeat(long start, long end) {
    long total = 0;
    for (long i = start; i <= end; i++) {
      String str = Long.toString(i);
      int L = str.length();
      boolean repeated = false;

      for (int j = 1; j <= L / 2; j++) {
        if (L % j != 0)
          continue;

        String block = str.substring(0, j);
        if (block.repeat(L / j).equals(str)) {
          repeated = true;
          break;
        }
      }
      if (repeated)
        total += i;
    }
    return total;
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String input = sc.nextLine();
    String[] items = input.split(",");
    long result = 0;
    for (String item : items) {
      String[] parts = item.split("-");
      long start = Long.parseLong(parts[0]);
      long end = Long.parseLong(parts[1]);
      result += checkRepeat(start, end);
    }
    sc.close();
    System.out.println(result);
  }
}
