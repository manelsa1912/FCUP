import java.util.*;
public class daa010 {
    public static void pesquisaBinaria(int s[], int low, int high, int x) {
        if (x < s[0]) {
            System.out.println(s[0]);
            return;
        }

        if (x > s[s.length - 1]) {
            System.out.println(s[s.length - 1]);
            return;
        }
        int m = 0;
        while (low <= high) {
            m = low + (high - low) / 2;
            if (s[m] == x) {
                System.out.println(s[m]);
                return;
            } else if (s[m] > x)
                high = m - 1;
            else
                low = m + 1;
        }
        if ((s[low] - x) < (x - s[high])) {
            System.out.println(s[low]);
        } 
        else if ((s[low] - x) == (x - s[high])) {
            System.out.println(s[high] + " " + s[low]);
        }
        else {
            System.out.println(s[high]);
        }
    }

    public static void main(String args[]) {
        Scanner stdin = new Scanner(System.in);
        int n = stdin.nextInt();
        int s[] = new int[n];

        int t = s.length;
        int n1 = (t * (t - 1) / 2); // formula slides
        int somas[] = new int[n1];
        for (int i = 0; i < n; i++)
            s[i] = stdin.nextInt();
        int k = 0;
        for (int i = 0; i < s.length; i++) {
            for (int j = i + 1; j < s.length; j++) {
                somas[k] = s[i] + s[j];
                k++;
            }
        }
        Arrays.sort(somas);

        int q = stdin.nextInt(); // qt perguntas
        int p[] = new int[q];
        for (int i = 0; i < q; i++) {
            p[i] = stdin.nextInt();
            pesquisaBinaria(somas, 0, somas.length - 1, p[i]);
        }
    }
}
