import java.util.Scanner;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.List;

/*
Nome: Manuel Sá
Número mecanográfico: 201805273
Sobre ajudas: Pesquisei se havia alguma forma de arredondar um valor para inteiro, e depois de surgir o problema de arredondamento para cima, fui procurar como arredondar para baixo no site: https://www.guj.com.br/t/arredondar-para-menos/75726
Explicação da solução:  na flag1 apenas foi preciso percorrer uma vez o ciclo; desse modo a complexidade no pior caso do meu programa fica O(ndias);
                        na flag2 criei um array novo para guardar os valores das sequencias e percorri-o; a complexidade será O(ndias-1);
                        na flag3 simulei a criaçao de uma matriz para gerar o grafico,logo precisei de dois ciclos.Neste caso a complexidade seria O(max*ndias) sendo max o maior numeros de casos/100.
*/

class Dia {
   float nCasos;

   Dia(int n) {
      this.nCasos = n;

   }

}

public class ED231 {

   public static Dia dia;
   public static List<Integer> arrayseq;

   public static float myRound(float d) {
      return (int) d;
   }

   public static void gerargrafico(Dia dias[]) {

      int max = Math.round(myRound(dias[dias.length - 1].nCasos / 100));
      for (int i = max; i > 0; i--) {
         // System.out.println("Max "+i);
         for (int k = 0; k < dias.length; k++) {

            if (dias[k].nCasos / 100 >= i)
               System.out.print('#');
            else
               System.out.print('.');
         }
         System.out.println();
      }

   }

   public static void main(String[] args) {
      Scanner stdin = new Scanner(System.in);
      int ndias = stdin.nextInt();
      Dia dias[] = new Dia[ndias];

      for (int i = 0; i < ndias; i++)
         dias[i] = new Dia(stdin.nextInt());

      int opcao = stdin.nextInt();

      if (opcao == 1) {
         int max = 0, min = 1000000;
         for (int i = 0, j = 1; j < ndias; i++, j++) {
            int val = Math.round(dias[j].nCasos - dias[i].nCasos);
            if (val > max)
               max = val;
            if (val < min)
               min = val;
         }
         System.out.print(Math.round(min) + " ");
         System.out.println(Math.round(max));
      }

      if (opcao == 2) {
         int maxseq = 0, seqsize = 0, seqcount = 0;
         float seqs[] = new float[ndias - 1];

         for (int k = 0, j = 1; j < ndias; k++, j++) {
            float b = ((dias[j].nCasos - dias[k].nCasos) / dias[k].nCasos) * 100;
            seqs[k] = b;
         }

         for (int l = 0, k = 1; k < ndias - 1; l++, k++) {
            if (l == 0 && seqs[l] <= 5) {
               seqsize++;
               seqcount++;
            }
            if (seqs[k] <= 5) {
               if (seqs[l] > 5)
                  seqcount++;
               seqsize++;
            }

            else {
               if (seqs[l] <= 5) {
                  if (seqsize >= maxseq)
                     maxseq = seqsize;
                  seqsize = 0;
               }
            }

            if (seqsize >= maxseq)
               maxseq = seqsize;

         }

         System.out.print(seqcount + " ");
         System.out.println(maxseq);
      }

      if (opcao == 3)
         gerargrafico(dias);

      stdin.close();
   }
}