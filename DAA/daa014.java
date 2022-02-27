import java.util.*;
   
    class Racio implements Comparable<Racio> {
        int dias,i;
        double rac,multas;

        public Racio(int i,int dias, double multas, double rac){
            this.i=i;
            this.dias=dias;
            this.multas=multas;
            this.rac=rac;
        }
        @Override
        
        public int compareTo(Racio racio) {
            if (rac > racio.rac) return +1;
            if (rac < racio.rac) return -1;
            return 0;
        }
    }

    public class daa014 {
    public static void main(String args[]) {
        
        Scanner stdin = new Scanner(System.in);
        int n = stdin.nextInt(); // nr de encomendas
        
        int dias=0;
        double multas=0;
        
        Racio[] ratio = new Racio[n];
        
        
        for(int i=0; i < n; i++){
            dias = stdin.nextInt();
            multas =stdin.nextInt();
            ratio[i] = new Racio(i,dias,multas,dias/multas);
        }
        
        Arrays.sort(ratio);
       
        for(int i=0; i <ratio.length-1;i++)
            System.out.print(ratio[i].i+1 + " ");
        System.out.print(ratio[ratio.length-1].i+1);
        
        System.out.println();
        }
}
