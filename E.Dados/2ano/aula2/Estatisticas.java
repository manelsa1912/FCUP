import java.util.Scanner;

public class Estatisticas {

   static void amp(int v[]){
      
   int max=v[0],min=v[1],amplitude;
      
      for(int i=0; i<v.length; i++){
         if(v[i]<=min) min=v[i];
         if(v[i]>=max) max=v[i];
      }

   amplitude=max-min;

   System.out.println(amplitude);
   }


   static void med(int v[]){
      
   float sum=0;
   float media;
      
      for(int i=0; i<v.length; i++){
        sum+=v[i];
      }

   media=sum/v.length;
   System.out.printf("%.2f\n", media);

   }


 public static void main(String[] args) {

      Scanner stdin = new Scanner(System.in);

      int n = stdin.nextInt();
      int v[] = new int[n];               
       
      
      for (int i=0; i<n; i++)   
         v[i] = stdin.nextInt(); 
      med(v);
      amp(v);         
   }
}