// -----------------------------------------------------------
// Estruturas de Dados 2019/2020 (CC1007) - DCC/FCUP
// http://www.dcc.fc.up.pt/~pribeiro/aulas/edados1920/
// -----------------------------------------------------------
// Lista ligada simples
// Ultima alteracao: 03/04/2018
// -----------------------------------------------------------

public class SinglyLinkedList<T> {
   private Node<T> first; // Primeiro no da lista
   private int size; // Tamanho da lista

   // Construtor (cria lista vazia)
   SinglyLinkedList() {
      first = null;
      size = 0;
   }

   // Retorna o tamanho da lista
   public int size() {
      return size;
   }

   // Devolve true se a lista estiver vazia ou falso caso contrario
   public boolean isEmpty() {
      return (size == 0);
   }

   // Adiciona v ao inicio da lista
   public void addFirst(T v) {
      Node<T> newNode = new Node<T>(v, first);
      first = newNode;
      size++;
   }

   // Adiciona v ao final da lista
   public void addLast(T v) {
      Node<T> newNode = new Node<T>(v, null);
      if (isEmpty()) {
         first = newNode;
      } else {
         Node<T> cur = first;
         while (cur.getNext() != null)
            cur = cur.getNext();
         cur.setNext(newNode);
      }
      size++;
   }

   // Retorna o primeiro valor da lista (ou null se a lista for vazia)
   public T getFirst() {
      if (isEmpty())
         return null;
      return first.getValue();
   }

   // Retorna o ultimo valor da lista (ou null se a lista for vazia)
   public T getLast() {
      if (isEmpty())
         return null;
      Node<T> cur = first;
      while (cur.getNext() != null)
         cur = cur.getNext();
      return cur.getValue();
   }

   // Remove o primeiro elemento da lista (se for vazia nao faz nada)
   public void removeFirst() {
      if (isEmpty())
         return;
      first = first.getNext();
      size--;
   }

   // Remove o ultimo elemento da lista (se for vazia nao faz nada)
   public void removeLast() {
      if (isEmpty())
         return;
      if (size == 1) {
         first = null;
      } else {
         // Ciclo com for e uso de de size para mostrar alternativa ao while
         Node<T> cur = first;
         for (int i = 0; i < size - 2; i++)
            cur = cur.getNext();
         cur.setNext(cur.getNext().getNext());
      }
      size--;
   }

   // Converte a lista para uma String
   public String toString() {
      String str = "{";
      Node<T> cur = first;
      while (cur != null) {
         str += cur.getValue();
         cur = cur.getNext();
         if (cur != null)
            str += ",";
      }
      str += "}";
      return str;
   }

   public SinglyLinkedList<T> reverse() {
      SinglyLinkedList<T> list = new SinglyLinkedList<T>();
      while (list.size < size) {
         list.addLast(getLast());
         T cur = getLast();
         removeLast();
         addFirst(cur);
      }
      return list;
   }

   public int[] occurrences(T elem) {

      int j = 0;

      for (int i = 0; i < size; i++) {
         // System.out.print(i);

         T val = getFirst();
         removeFirst();
         addLast(val);
         if (elem.equals(val)) {
            j++;

         }
      }
      int pos[] = new int[j];
      if(j==0) return null;
      //System.out.println("j = " + j);
      for (int l = 0,k=0; l < size; l++) {
         T val2 = getFirst();
         removeFirst();
         addLast(val2);
        // System.out.println(" valor atual " + val2);
         if (elem.equals(val2)) {
            //System.out.println("Posiçao no mom = " + l);
            //System.out.println("k = " + k);
            pos[k] = l;
            //System.out.println("pos k = " + pos[k]);
            k++;  
         }
      }

      return pos;
   }

   public void remove(SinglyLinkedList<T> toRemove) {

      for (int i = 0; i < toRemove.size; i++) {
         T val = toRemove.getFirst();
         toRemove.removeFirst();
         toRemove.addLast(val);

         for (int j = 0; j <= size; j++) {
            T val2 = getFirst();
            //System.out.println("Este é o "+ val2);
            if (val.equals(val2)){
               removeFirst();
               //System.out.println("Tirei o "+ val2);
            }
            else {
               removeFirst();
               addLast(val2);
            }

         }
      }
   }

}
