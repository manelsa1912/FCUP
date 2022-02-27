// Manuel Sá up201805273
/* flag1 - Ao cria-se a árvre e incrementar a uma variavel sempre que um filme
que nao estava na arvore.
   flag2 - percorrer a árvore e verificar qual das avaliaçoes é a maior e colocar
na variavel de retorno.
   flag3 - Ao percorrer a TAD e ao usar mesma estratégia na flag 2, somar as
avaliaçoes acima de 5 e somar o numero de filmes. Fazer a media e colocar no valor que vai dividir.
no fim imprimir porque já estao ordenados por ordem alfabética.

*/


import java.util.Scanner;

public class ED234 {

   public static void main(String[] args) {

      Scanner in = new Scanner(System.in);

      BSTMap<String, Integer> rate = new BSTMap<>();

      BSTree<String> movies = new BSTree<String>();

      BSTMap<String, Integer> rmovies = new BSTMap<>();

      int flag = in.nextInt();

      int nmovies = in.nextInt();

      String nmline = in.nextLine();

      for (int i = 0; i < nmovies; i++) {

         String line = in.nextLine();

         String[] rates = line.split(" ");

         int v = Integer.parseInt(rates[1]);

         switch(flag){
            
            case 1: movies.insert(rates[0]);
                     break;

            case 2: {
           
               if (rmovies.get(rates[0]) == null)
                  rmovies.put(rates[0], 1);
               else {
                  int valorant = rmovies.get(rates[0]);
                  valorant++;
                  rmovies.put(rates[0], valorant);
               }
               break;
            }

            case 3: {
               if (rmovies.get(rates[0]) == null)
                  rmovies.put(rates[0], 1);
               else {
                  int valorant = rmovies.get(rates[0]);
                  valorant++;
                  rmovies.put(rates[0], valorant);
               }

               if (rate.get(rates[0]) == null)
                  rate.put(rates[0], v);
               else {
                  int valorant = rate.get(rates[0]);
                  rate.put(rates[0], valorant + v);
               }
               break;
            }
         }
      }

      switch(flag){
   
         case 1: System.out.println(movies.numberNodes());
                  break;
         
         case 2: {
            int max = 0;
            String filme = "";
            for (String i : rmovies.keys()) {
               if (rmovies.get(i) > max) {
                  max = rmovies.get(i);
                  filme = i;
               }
            }
            System.out.println(filme + " " + max);
            break;
         }

         case 3: {
            for (String j : rate.keys()) {
               int media = rate.get(j) / rmovies.get(j);
               if (media >= 5) {
                  System.out.println(j);
               }
            }
            break;
         }
      }
   }
}