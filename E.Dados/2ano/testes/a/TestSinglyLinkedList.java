// -----------------------------------------------------------
// Estruturas de Dados 2019/2020 (CC1007) - DCC/FCUP
// http://www.dcc.fc.up.pt/~pribeiro/aulas/edados1920/
// -----------------------------------------------------------
// Exemplo de utilizacao da lista ligada simples
// Ultima alteracao: 01/04/2018
// -----------------------------------------------------------
import java.util.Arrays;
import java.util.ArrayList;

public class TestSinglyLinkedList {
   public static void main(String[] args) {

      // Criacao de lista de inteiros
      SinglyLinkedList<Integer> list = new SinglyLinkedList<Integer>();
     

      // Escrevendo lista (no inicio esta vazia)
      System.out.println(list);

      // Verificando se esta vazia
      System.out.println("isEmpty? " + list.isEmpty());     
      
      // Adicionando numeros de 1 a 5 ao final da lista
      
      list.addFirst(10);
      list.addFirst(8);
      list.addFirst(6);
      list.addFirst(4);
      list.addFirst(2);

      System.out.println(list);
     // remover.addLast('a');
      //remover.addLast('b');
      //remover.addLast('d');
      //remover.addLast('a');
      //remover.addLast('c');

      
      //System.out.println(remover);
      // Verificando o tamanho da lista
      System.out.println("size = " + list.size());

      // Retirando o primeiro elemento
     /* list.removeFirst();
      System.out.println(list);*/

      // Retirando o ultimo elemento
     // list.removeLast();
      //System.out.println(list);

      // Verificando se esta vazia
      System.out.println("isEmpty? " + list.isEmpty());

      // Escreve o primeiro e ultimo elementos
      System.out.println("getFirst() = " + list.getFirst());
      System.out.println("getLast() = " + list.getLast());
      
      //Faz o inverso da lista
     // int[] result = list.occurrences('a');
    
    //System.out.println(Arrays.toString(result));
      //System.out.print("ocorrencia(8) = " + list.occurrences(8).toString());
     // list.remove(remover);
     // System.out.println("Remover  a = " + list);

     SinglyLinkedList<Integer> r = list.cut(0,2);
     System.out.println("CUT "+r);
   }
}