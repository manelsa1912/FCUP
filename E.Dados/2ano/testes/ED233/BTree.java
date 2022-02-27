import java.util.LinkedList;

// -----------------------------------------------------------
/* Manuel Sá - up201805273
implementaçao: inter nodes - Percorrer a arvore e verificar se cada no possui a pelo menos
um valor à esquerda ou à direita. Caso tivesse, incrementava se na soluçao.
Quando ambos os ramos do nó fossem nulos, paravamos a pesquisa naquele nó e
quando estiverem todos vistos temos a soluçao.
               cut - percorrer a árvore com uma variavel auxiliar que me determina a profundidade
do nó em que estou. caso essa variavel fosse igual à do input, aquele nó passaria a apontar para 
nulo, tanto à esquerda como à direita. Caso um nó seja nulo retorna e temos assim a árvore cortada.
               maxlevel - criei uma lista auxiliar para me guardadr o número de nós em cada nivel
(a posiçao na lista corresponde ao nivel na arvore). Sempre que encontro um no novo, incremento o valor
guardado naquela posiçao da lista. Depois verifico se aquele valor é máximo e se for coloco na soluçao
ou se for igual incremento ao segundo valor da soluçao.

*/
// -----------------------------------------------------------

public class BTree<T> {
   private BTNode<T> root; // raiz da arvore

   // Construtor
   BTree() {
      root = null;
   }

   // Getter e Setter para a raiz
   public BTNode<T> getRoot() {
      return root;
   }

   public void setRoot(BTNode<T> r) {
      root = r;
   }

   // Verificar se arvore esta vazia
   public boolean isEmpty() {
      return root == null;
   }

   // --------------------------------------------------------

   // Numero de nos da arvore
   public int numberNodes() {
      return numberNodes(root);
   }

   private int numberNodes(BTNode<T> n) {
      if (n == null)
         return 0;
      return 1 + numberNodes(n.getLeft()) + numberNodes(n.getRight());
   }

   // --------------------------------------------------------

   // Altura da arvore
   public int depth() {
      return depth(root);
   }

   private int depth(BTNode<T> n) {
      if (n == null)
         return -1;
      return 1 + Math.max(depth(n.getLeft()), depth(n.getRight()));
   }

   // --------------------------------------------------------

   // O elemento value esta contido na arvore?
   public boolean contains(T value) {
      return contains(root, value);
   }

   private boolean contains(BTNode<T> n, T value) {
      if (n == null)
         return false;
      if (n.getValue().equals(value))
         return true;
      return contains(n.getLeft(), value) || contains(n.getRight(), value);
   }

   // --------------------------------------------------------

   // Imprimir arvore em PreOrder
   public void printPreOrder() {
      System.out.print("PreOrder:");
      printPreOrder(root);
      System.out.println();
   }

   private void printPreOrder(BTNode<T> n) {
      if (n == null)
         return;
      System.out.print(" " + n.getValue());
      printPreOrder(n.getLeft());
      printPreOrder(n.getRight());
   }

   // --------------------------------------------------------

   // Imprimir arvore em InOrder
   public void printInOrder() {
      System.out.print("InOrder:");
      printInOrder(root);
      System.out.println();
   }

   private void printInOrder(BTNode<T> n) {
      if (n == null)
         return;
      printInOrder(n.getLeft());
      System.out.print(" " + n.getValue());
      printInOrder(n.getRight());
   }

   // --------------------------------------------------------

   // Imprimir arvore em PostOrder
   public void printPostOrder() {
      System.out.print("PostOrder:");
      printPostOrder(root);
      System.out.println();
   }

   private void printPostOrder(BTNode<T> n) {
      if (n == null)
         return;
      printPostOrder(n.getLeft());
      printPostOrder(n.getRight());
      System.out.print(" " + n.getValue());
   }

   // --------------------------------------------------------

   // Imprimir arvore numa visita em largura (usando TAD Fila)
   public void printBFS() {
      System.out.print("BFS:");

      MyQueue<BTNode<T>> q = new LinkedListQueue<BTNode<T>>();
      q.enqueue(root);
      while (!q.isEmpty()) {
         BTNode<T> cur = q.dequeue();
         if (cur != null) {
            System.out.print(" " + cur.getValue());
            q.enqueue(cur.getLeft());
            q.enqueue(cur.getRight());
         }
      }
      System.out.println();
   }

   // --------------------------------------------------------

   // Imprimir arvore numa visita em profundidade (usando TAD Pilha)
   public void printDFS() {
      System.out.print("DFS:");

      MyStack<BTNode<T>> q = new LinkedListStack<BTNode<T>>();
      q.push(root);
      while (!q.isEmpty()) {
         BTNode<T> cur = q.pop();
         if (cur != null) {
            System.out.print(" " + cur.getValue());
            q.push(cur.getLeft());
            q.push(cur.getRight());
         }
      }
      System.out.println();
   }

   public int internal() {
      if (root == null)
         return 0;

      int interNodes = internal(root);
      return interNodes;
   }

   public int internal(BTNode<T> n) {
      int interNodes = 0;
      if ((n.getLeft() != null) || (n.getRight() != null)) {
         interNodes++;
         if (n.getLeft() != null)
            interNodes += internal(n.getLeft());
         if (n.getRight() != null)
            interNodes += internal(n.getRight());
      }
      return interNodes;
   }

   public void cut(int d) {
      if (d <= 0) {
         root = null;
         return;
      }
      int s = 0;
      cut(d, s, root);

   }

   public void cut(int d, int s, BTNode<T> n) {
      
      if(n==null) return;
      if (s == d-1){
         n.setLeft(null);
         n.setRight(null);
      }
      else{
         cut(d, s + 1, n.getLeft());
         cut(d, s + 1, n.getRight());        
      }
   }

   public int[] maxLevel(){
      int [] s = new int[2];
      int [] lista = new int[depth()];
      
      for (int i : lista) {
         lista[i]=0;
      }
      lista[0]=1;
      s[0]=1;
      s[1]=1;
      maxLevel(s,root,lista,0);
      return s;
   }
   public void maxLevel(int[] s, BTNode<T> n, int[] lista,int level){
      System.out.println("level " + level);
      
      if(n==null) return;
      else{
         lista[level]++;
         if(lista[level]>s[0]){
            s[0]=lista[level];
            s[1]=0;
         }
         if(lista[level]==s[0]) s[1]++;
         maxLevel(s,n.getRight(),lista,level+1);
         maxLevel(s,n.getLeft(),lista,level+1);
      }
     
      System.out.println("nos no nivel = " + lista[level]);
      System.out.println();
   }

}
