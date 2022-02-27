import java.util.Scanner;

public class ReadNumbers {

   // Escrever os numeros guardados num array no stdout
   static void writeArray(int v[]) {
      for (int i=0; i<v.length; i++)          
         System.out.println("v[" + i + "] = " + v[i]);      
   }

   static void amp(int v[]){
      
   int max=v[0],min=v[1],amplitude;
      
      for(int i=0; i<v.length; i++){
         if(v[i]<=min) min=v[i];
         if(v[i]>=max) max=v[i];
      }

   amplitude=max-min;

   System.out.println(amplitude);
   }


   
   public static void main(String[] args) {

      Scanner stdin = new Scanner(System.in);

      int v[] = new int[10];     // Cria um novo array com espaço para 10 inteiros           
      int n = stdin.nextInt();   // Ler a quantidade de numeros que se seguem
      
      for (int i=0; i<n; i++)    // Ler os numeros a partir do stdin
         v[i] = stdin.nextInt();
      
      writeArray(v);  
      amp(v);           // Chamar procedimento que escreve
   }
}