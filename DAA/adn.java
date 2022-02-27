import java.util.Scanner;
import java.util.Arrays;

public class Adn {
    public static void main(String[] args) {
        Scanner letras = new Scanner(System.in); 
        String frag = letras.nextLine();
        char fragArray[] = frag.toCharArray();
        Arrays.sort(fragArray);
        
        char curr = fragArray[0];
        int sumcurr = 1;
        
        for(int i=1;i<frag.length();i++){
            if(fragArray[i]==curr) sumcurr++;
            else{
                System.out.print(curr + " ");
                System.out.println(sumcurr);
                curr=fragArray[i];
                sumcurr=1; 
            }
        }
                System.out.print(curr + " ");
                System.out.println(sumcurr);

    }
}
