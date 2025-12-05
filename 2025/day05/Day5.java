import java.util.*;

public class Day5 {

    static class Range {

        long start, end;

        Range(long s, long e) {
            start = s;
            end = e;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<Range> ranges = new ArrayList<>();
        List<Long> ids = new ArrayList<>();

        while (sc.hasNextLine()) {
            String line = sc.nextLine().trim();
            if (line.isEmpty()) break;
            String[] p = line.split("-");
            long a = Long.parseLong(p[0]);
            long b = Long.parseLong(p[1]);
            ranges.add(new Range(a, b));
        }

        while (sc.hasNextLine()) {
            String line = sc.nextLine().trim();
            if (line.isEmpty()) continue;
            ids.add(Long.parseLong(line));
        }
        sc.close();

        ranges.sort(Comparator.comparingLong(r -> r.start));
        List<Range> merged = new ArrayList<>();
        for (Range r : ranges) {
            if (
                merged.isEmpty() || r.start > merged.get(merged.size() - 1).end
            ) {
                merged.add(new Range(r.start, r.end));
            } else {
                merged.get(merged.size() - 1).end = Math.max(
                    merged.get(merged.size() - 1).end,
                    r.end
                );
            }
        }
        int count = 0;
        for (long x : ids) {
            if (inRange(merged, x)) count++;
        }
        long total = 0;
        for (Range r : merged) {
            total += r.end - r.start + 1;
        }
        System.out.println(count);
        System.out.println(total);
    }

    static boolean inRange(List<Range> ranges, long x) {
        int left = 0,
            right = ranges.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            Range r = ranges.get(mid);
            if (x < r.start) {
                right = mid - 1;
            } else if (x > r.end) {
                left = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
}
