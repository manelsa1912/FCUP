import java.util.Scanner;

public class ED235 {
  public static void main (String[] args) {
    Scanner read = new Scanner(System.in);
    int n = read.nextInt();
   
    for( int i = n; i > 0 ; i-- ) {
      
      int n1 = read.nextInt();

      for(int j = n1; j > 0 ; j--){
         
         for(int k=1;k<=n1;k++){
            
            if(k>=j) System.out.print('#');
            else System.out.print('.');
         }
         
         System.out.println();
      }
   }

   }
}