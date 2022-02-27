public class Square {
    // Desenha uma linha de n caracteres onde:
    // - o primeiro e o último caracteres são o caracter da variável 'a'
    // - todos os outros caracteres são o caracter da variável 'b'
    static void line(char a, char b, int n) {
	System.out.print(a);
	for (int i=1; i<=n-2; i++)
	    System.out.print(b);
	System.out.println(a);
    }

    static void sqr(char a, char b, char c, char d,int n){
      line(a,b,n);
      for(int i = 1;i<=n-2;i++) line(c,d,n);
      line(a,b,n);
   }

    // O procedimento executado inicialmente é sempre o main
    public static void main(String[] args) {	
	sqr('+','-','|','.',5);	    
    }
}