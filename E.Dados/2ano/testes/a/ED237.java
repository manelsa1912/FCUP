import java.util.Scanner;

public class process{
   String name;
   int t_inicial;
   int t_final;
}

public class ED237 {
   

   public static void main(String[] args) {

      Scanner in = new Scanner(System.in);
     
      CircularLinkedList<process> list = new CircularLinkedList<process>();

      int time=in.nextInt();
      int nprocss=in.nextInt();
      
      for(int i=0;i<nprocss;i++){
         process p;
         p.name=in.nextLine();
         
         
         list.addFirst(p);
      }


    
     
     

   }
}