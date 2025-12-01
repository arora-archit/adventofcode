import java.util.Scanner;

class Node {
  int value;
  Node next;
  Node prev;
  Node(int value) { this.value = value; }
}

public class Day1 {
  public static void main(String[] args) {
    Node head = null;
    Node prev = null;

    for (int i = 0; i < 100; i++) {
      Node n = new Node(i);
      if (prev != null) {
        prev.next = n;
        n.prev = prev;
      } else {
        head = n;
      }
      prev = n;
    }

    head.prev = prev;
    prev.next = head;

    Node ptr = head;
    while (ptr.value != 50)
      ptr = ptr.next;

    int countZero = 0;
    Scanner sc = new Scanner(System.in);
    while (sc.hasNext()) {
      String inp = sc.next();
      char dir = inp.charAt(0);
      int count = Integer.parseInt(inp.substring(1));

      for (int i = 0; i < count; i++) {
        if (dir == 'L') {
          ptr = ptr.prev;
        } else
          ptr = ptr.next;
        if (ptr.value == 0)
          countZero++;
      }
    }
    sc.close();
    System.out.println(countZero);
  }
}
