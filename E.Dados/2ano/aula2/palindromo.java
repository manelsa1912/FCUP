import.java.util.Scanner;

public class Palindromo{


   static void pal(char v[]){

      for(int i=0,j=v.length;i!=j;i++,j--){

         if((Character.isLetter(v[i]))&&(Character.isLetter(v[j]))){
         
         Character.toLowerCase(v[i]);
         Character.toLowerCase(v[j]);  
         if(v[i]!=v[j]) System.out.println("Não");

         }


      }
   }










   public static void main(String[] args) {
	
      Scanner stdin = new Scanner(System.in);
      int n=stdin.nextInt();
        		
       while (int i=0<n) {
        
         if(i==0) System.out.println(n);
            else{
            String s = stdin.nextLine();
            pal(s);
            }
      }
   }
}